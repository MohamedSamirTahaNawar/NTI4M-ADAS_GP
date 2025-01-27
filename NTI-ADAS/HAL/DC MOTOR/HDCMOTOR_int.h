#ifndef HDCMOTOR_INTERFACE_H
#define HDCMOTOR_INTERFACE_H
#include "MGPIO_int.h"
#include "ERROR_STATE.h"
#include "HDCMOTOR_cfg.h"

ErrorState_t HDCMotor_u8RotatCW(MGPIO_PORT_t copy_u8PortNumber,MGPIO_PIN_t copy_u8CWPin,MGPIO_PIN_t copy_u8CCWPin );
ErrorState_t HDCMOTOR_u8RotatCCW(MGPIO_PORT_t copy_u8PortNumber,MGPIO_PIN_t copy_u8CWPin,MGPIO_PIN_t copy_u8CCWPin );
ErrorState_t HDCMOTOR_u8Stop(MGPIO_PORT_t copy_u8PortNumber,MGPIO_PIN_t copy_u8CWPin,MGPIO_PIN_t copy_u8CCWPin);



#endif
