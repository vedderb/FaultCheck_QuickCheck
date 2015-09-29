#include "application.h"
#include "E2E_P01.h"
#include "faultcheck_packet_wrapper.h"
#include <string.h>

/*
 * Printf has to he declared here because including stdio.h causes
 * problems for QuickCheck.
 */
int printf ( const char * format, ... );

/*
 * The airbag_active variable shows if the airbag is exploded or not,
 * and is read from QuickCheck. Then the QuickCheck model determines
 * whether this is correct or not.
 */
int airbag_active;

// Other variables
int activations;
E2E_P01SenderStateType sender_state;
E2E_P01ConfigType config;
E2E_P01ReceiverStateType receiver_state;

/*
 * Set up the AUTOSAR E2E-library and reset the state
 * of the application.
 */
void application_init() {
	memset(&sender_state, 0, sizeof(sender_state));
	memset(&receiver_state, 0, sizeof(receiver_state));
	memset(&config, 0, sizeof(config));

	airbag_active = 0;
	activations = 0;

	config.CounterOffset = 3 * 8;
	config.CRCOffset = 0;
	config.DataIDMode = E2E_P01_DATAID_BOTH;
	config.DataLength = 2 * 8;
	config.MaxDeltaCounterInit = 3;
}

/*
 * Pass "sensor" data to the FaultCheck communication channel.
 */
void sensor(unsigned char *data) {
	faultcheck_packet_addPacket("airbag", (char*)data, 2);
}

/*
 * Read data from the FaultCheck communication channel as long as
 * there is data available. If the data matches [85, 170] increase a
 * counter and explode the airbag if that counter is 2 or more.
 */
void airbag_iteration() {
	unsigned char data[2];
	int len;

	while (faultcheck_packet_getPacket("airbag", (char*)data, &len)) {
		if (data[0] == 85 && data[1] == 170) {
			activations++;
		} else {
			activations = 0;
		}

		if (activations >= 2 && !airbag_active) {
			airbag_active = 1;
			printf("========== EXPLODE!! ======== \r\n");
		}
	}
}

/*
 * Same as the other sensor function, but uses the AUTOSAR E2E-library
 * to protect the data.
 */
void sensor_e2e(unsigned char *data) {
	unsigned char buffer[4];

	buffer[1] = data[0];
	buffer[2] = data[1];

	E2E_P01Protect(&config, &sender_state, buffer);
	faultcheck_packet_addPacket("airbag", (char*)buffer, 4);
}

/*
 * Same as the other iteration function, but uses the AUTOSAR
 * E2E-library to check the data.
 */
void airbag_iteration_e2e() {
	unsigned char data[4];
	int len;

	do {
		receiver_state.NewDataAvailable =
				faultcheck_packet_getPacket("airbag", (char*) data, &len);
		E2E_P01Check(&config, &receiver_state, data);

		if (receiver_state.Status == E2E_P01STATUS_OK) {
			if (data[1] == 85 && data[2] == 170) {
				activations++;
			} else {
				activations = 0;
			}

			if (activations >= 2 && !airbag_active) {
				airbag_active = 1;
				printf("========== EXPLODE!! ======== \r\n");
			}
		}
	} while (receiver_state.Status != E2E_P01STATUS_NONEWDATA);
}
