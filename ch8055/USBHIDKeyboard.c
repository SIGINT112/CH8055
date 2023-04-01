#include <stdint.h>
#include <stdbool.h>
#include "include/ch5xx.h"
#include "include/ch5xx_usb.h"
#include "USBconstant.h"
#include "USBhandler.h"

extern __xdata __at (EP0_ADDR) uint8_t  Ep0Buffer[];
extern __xdata __at (EP1_ADDR) uint8_t  Ep1Buffer[];

volatile __xdata uint8_t UpPoint1_Busy  = 0;   //Flag of whether upload pointer is busy

__xdata uint8_t HIDKey[8] = {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};



typedef void( *pTaskFn)( void );

void delayMicroseconds(uint16_t us);

void USBInit(){
    USBDeviceCfg();                                                       //Device mode configuration
    USBDeviceEndPointCfg();                                               //Endpoint configuration   
    USBDeviceIntCfg();                                                    //Interrupt configuration    
    UEP0_T_LEN = 0;
    UEP1_T_LEN = 0;                                                       //Pre-use send length must be cleared	  
    UEP2_T_LEN = 0;                                                          
}



void USB_EP1_IN(){
    UEP1_T_LEN = 0;
    UEP1_CTRL = UEP1_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_NAK;           // Default NAK
    UpPoint1_Busy = 0;                                                  //Clear busy flag
}


volatile extern uint8_t dout;

void USB_EP1_OUT(){
    if ( U_TOG_OK )                                                     // Discard unsynchronized packets
    {
		switch(Ep1Buffer[0]){
			case 0:break;
			case 1:break;
			case 2:break;
			case 3:break;
			case 4:break;
			case 5:dout=Ep1Buffer[1];break;
			default:break;
			
			
			
			}
    }
}

uint8_t USB_EP1_send(){
   
    
    for (uint8_t i=0;i<sizeof(HIDKey);i++){                                  //load data for upload
        Ep1Buffer[64+i] = HIDKey[i];
    }
                   
    UEP1_T_LEN = sizeof(HIDKey);                                             //data length
    UpPoint1_Busy = 1;
    UEP1_CTRL = UEP1_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;                //upload data and respond ACK
    
    return 1;
}

uint8_t Keyboard_press(uint8_t x,uint8_t y,uint8_t z,uint8_t k) {
	HIDKey[0]=x;
	HIDKey[1]=y;
	HIDKey[2]=z;
	HIDKey[3]=k;
	USB_EP1_send();
	return 1;
}

