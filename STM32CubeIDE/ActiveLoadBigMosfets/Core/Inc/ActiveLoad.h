/*
 * ActiveLoad.hpp
 *
 *  Created on: May 16, 2020
 *      Author: Chipotle
 */

#ifndef INC_ACTIVELOAD_H_
#define INC_ACTIVELOAD_H_

#ifdef __cplusplus
extern "C" {
#endif

extern void ActiveLoad_init();

extern void ActiveLoad_loop();

extern void ActiveLoad_EncoderTick();

void ActiveLoad_processMessages();

#ifdef __cplusplus
}
#endif

#endif /* INC_ACTIVELOAD_H_ */
