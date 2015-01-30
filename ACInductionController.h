#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "p30F4011.h"
//#include "UART4011.h"
#include <libpic30.h>

#define I_TRIS_THROTTLE 		_TRISB0
#define I_TRIS_CURRENT1			_TRISB1
#define I_TRIS_CURRENT2			_TRISB2
#define I_TRIS_INDEX			_TRISB3
#define I_TRIS_QEA				_TRISB4
#define I_TRIS_QEB				_TRISB5
#define O_TRIS_CLEAR_FLIP_FLOP	_TRISB6
#define I_TRIS_TEMPERATURE		_TRISB7
#define I_TRIS_REGEN_THROTTLE	_TRISB8
#define I_TRIS_DESAT_FAULT		_TRISC13
#define I_TRIS_OVERCURRENT_FAULT 	_TRISC14
#define I_TRIS_UNDERVOLTAGE_FAULT	_TRISE8
#define O_TRIS_LED  			_TRISD1 // high means turn ON the LED.
#define O_TRIS_PRECHARGE_RELAY	_TRISD3	// HIGH means turn ON the precharge relay.
#define I_TRIS_GLOBAL_FAULT		_TRISD2
#define O_TRIS_CONTACTOR		_TRISD0
#define O_TRIS_CLEAR_DESAT		_TRISF6
#define O_TRIS_PWM_3H			_TRISE5
#define O_TRIS_PWM_3L			_TRISE4
#define O_TRIS_PWM_2H			_TRISE3
#define O_TRIS_PWM_2L			_TRISE2
#define O_TRIS_PWM_1H			_TRISE1
#define O_TRIS_PWM_1L			_TRISE0

#define I_LAT_THROTTLE 			_LATB0
#define I_LAT_CURRENT1			_LATB1
#define I_LAT_CURRENT2			_LATB2
#define I_LAT_INDEX				_LATB3
#define I_LAT_QEA				_LATB4
#define I_LAT_QEB				_LATB5
#define O_LAT_CLEAR_FLIP_FLOP	_LATB6
#define I_LAT_TEMPERATURE		_LATB7
#define I_LAT_REGEN_THROTTLE	_LATB8
#define I_LAT_DESAT_FAULT		_LATC13
#define I_LAT_OVERCURRENT_FAULT _LATC14
#define I_LAT_UNDERVOLTAGE_FAULT	_LATE8
#define O_LAT_LED  				_LATD1 // high means turn ON the LED.
#define O_LAT_PRECHARGE_RELAY	_LATD3	// HIGH means turn ON the precharge relay.
#define I_LAT_GLOBAL_FAULT		_LATD2
#define O_LAT_CONTACTOR			_LATD0
#define O_LAT_CLEAR_DESAT		_LATF6
#define O_LAT_PWM_3H			_LATE5
#define O_LAT_PWM_3L			_LATE4
#define O_LAT_PWM_2H			_LATE3
#define O_LAT_PWM_2L			_LATE2
#define O_LAT_PWM_1H			_LATE1
#define O_LAT_PWM_1L			_LATE0

#define I_PORT_THROTTLE 		_RB0
#define I_PORT_CURRENT1			_RB1
#define I_PORT_CURRENT2			_RB2
#define I_PORT_INDEX			_RB3
#define I_PORT_QEA				_RB4
#define I_PORT_QEB				_RB5
#define O_PORT_CLEAR_FLIP_FLOP	_RB6
#define I_PORT_TEMPERATURE		_RB7
#define I_PORT_REGEN_THROTTLE	_RB8
#define I_PORT_DESAT_FAULT		_RC13
#define I_PORT_OVERCURRENT_FAULT _RC14
#define I_PORT_UNDERVOLTAGE_FAULT	_RE8
#define O_PORT_LED  			_RD1 // high means turn ON the LED.
#define O_PORT_PRECHARGE_RELAY	_RD3	// HIGH means turn ON the precharge relay.
#define I_PORT_GLOBAL_FAULT		_RD2
#define O_PORT_CONTACTOR		_RD0
#define O_PORT_CLEAR_DESAT		_RF6
#define O_PORT_PWM_3H			_RE5
#define O_PORT_PWM_3L			_RE4
#define O_PORT_PWM_2H			_RE3
#define O_PORT_PWM_2L			_RE2
#define O_PORT_PWM_1H			_RE1
#define O_PORT_PWM_1L			_RE0

#define THROTTLE_RAMP_RATE 16

#define THROTTLE_FAULT (1u << 0)
#define DESAT_FAULT (1u << 1)
#define UART_FAULT (1u << 2)
#define UV_FAULT (1u << 3)
#define OVERCURRENT_FAULT (1u << 4)

#define VREF_FAULT (1u << 5)
#define MOTOR_OVERSPEED_FAULT (1u << 6)
#define ROTOR_FLUX_ANGLE_FAULT (1u << 7)
#define GLOBAL_FAULT (1u << 8)
#define PI_OVERFLOW_FAULT (1u << 9)
#define PDC_FAULT (1u << 10)
#define RPS_FAULT (1u << 11)
#define MC_OVERFLOW_FAULT (1u << 12)
#define ENCODER_CABLE_UNPLUGGED_FAULT (1u << 13)
#define CONFIG_FAULT (1u << 14)
#define LINE_TO_LINE_CURRENT_FAULT (1u << 15)

#define THROTTLE_REGEN_START 344
#define THROTTLE_REGEN_END 103
#define THROTTLE_START 474
#define THROTTLE_END 921
#define ZERO_TO_5K_POT 1
#define THROTTLE_FAULT_COUNTS 20		// after 100mS, flag a throttle fault.
#define BAUD_RATE 19200
#define DELAY_200MS_SLOW_TIMER 11719  // 117.188KHz clock, 200ms.
#define THERMAL_CUTBACK_START 670	// 75degC
#define THERMAL_CUTBACK_END 726	// 85degC
// max temperature is 726, which is 85degC.

#define R_MAX 863u	// 863 * 2/sqrt(3) * 1.5 = 1494.  Max duty is 1500. due to scaling of inverse clarke. 2/sqrt(3) I forgot now.  haha.
#define R_MAX_TIMES_65536 (863UL << 16)
#define MAX_VD_VQ 15000L
#define MAX_MAGNETIZING_CURRENT 4096
#define MAX_SLIP_SPEED_RPS_TIMES16 6400
#define MAX_RPS_TIMES16 3200
#define MAX_LONG_INT 2147483647L
#define MAX_DUTY 1499 // I think you can actually go to 1500, but whatever.  haha.  I'm staying away from the edges.
#define MAX_MOTOR_AMPS 400
#define MAX_BATTERY_AMPS_REGEN 50
#define MAX_BATTERY_AMPS 400
#define MAX_CURRENT_SENSOR_AMPS_PER_VOLT 1000  // LEM Hass 300-s is 480.  Hass 50-s is 80.  Hass 600-s is 960.
#define MAX_ROTOR_TIME_CONSTANT_INDEX 145u // valid indices are 0 to 145 inclusive.
#define DEFAULT_CURRENT_SENSOR_AMPS_PER_VOLT 16 // default is the LEM Hass 50-s with 5 wraps at the moment.

typedef struct {
	int Kp_Id;						// PI loop proportional gain
	int Ki_Id;						// PI loop integreal gain
	int Kp_Iq;						
	int Ki_Iq;
	int currentSensorAmpsPerVolt;					
	int maxRegenPosition;			//
	int minRegenPosition;			//
	int minThrottlePosition;		//
	int maxThrottlePosition;		
	int throttleFaultPosition;		
	int maxBatteryAmps;				// 
	int maxBatteryAmpsRegen;		// 
	int maxMotorAmps;
	int maxMotorAmpsRegen;
	int prechargeTime;				// precharge time in 0.1 second increments
	unsigned crc;					
} SavedValuesStruct;

typedef struct {
	int rotorTimeConstantIndex;  	// 31 and 32 is the best for my motor. 0 corresponds to rotor time constant of 0.005 seconds.  145 corresponds to 0.150 seconds.
	int numberOfPolePairs;			// number of pole pairs.  If the nameplate says around 1700RPM on a 60Hz 3 phase, then it's 2 pole pairs.  3400RPM (or so) means 1 pole pair.
	int maxRPM;
	int throttleType;				// 0 = hall effect or "Max Ohms to Min Ohms" if using Pot.  1 = MIN OHMS to MAX OHMS.
	int spares[11];
	unsigned crc;
} SavedValuesStruct2;

typedef struct {
	int throttle;
	unsigned temperatureBasePlate;
	unsigned temperatureMotor;
	int IqRef;
	int IdRef;
	int Id;
	int Iq;
	unsigned pdc1;
	unsigned pdc2;
	unsigned pdc3;
	int RPS_times16;
	unsigned batteryCurrentNormalized; 
	unsigned faultBits;  
} realtime_data_type;

typedef struct {
	long P;
	long I;
	long error;
	long errorSum;
	long pwm;
} piType;

#define DEBUG

#endif