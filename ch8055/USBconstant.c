#include "USBconstant.h"



//Device descriptor
__code uint8_t DevDesc[] = {
    0x12,0x01,
    0x10,0x01,  //USB spec release number in BCD format, USB1.1 (0x10, 0x01).
    0x00,0x00,0x00, //bDeviceClass, bDeviceSubClass, bDeviceProtocol 
    DEFAULT_ENDP0_SIZE, //bNumConfigurations
    0xCF,0x10,0x02,0x55, // VID PID 
    0x00,0x00,  //version
    0x01,0x02,0x03, //bString
    0x01    //bNumConfigurations
};

__code uint16_t DevDescLen = sizeof(DevDesc);

__code uint8_t CfgDesc[] ={
    0x09,0x02,sizeof(CfgDesc) & 0xff,sizeof(CfgDesc) >> 8,
    0x01,0x01,0x00,0x80,0x64,             //Configuration descriptor (1 interface)
    // Interface 1 (HID) descriptor
    0x09,0x04,0x00,0x00,0x02,0x03,0x00,0x00,0x00,    // HID Keyboard, 2 endpoints
    0x09,0x21,0x00,0x01,0x21,0x01,0x22,sizeof(ReportDesc) & 0xff,sizeof(ReportDesc) >> 8,    //HID Descriptor
    0x07,0x05,0x81,0x03,0x08,0x00,0x0A,                       //endpoint descriptor
	0x07,0x05,0x01,0x03,0x08,0x00,0x0A,    
	};

__code uint16_t ReportDescLen = sizeof(ReportDesc);

/*
__code uint8_t ReportDesc[] ={
   0x05, 0x01,     // USAGE_PAGE (Generic Desktop)
	0x09, 0x05,     // USAGE (Game Pad)
	0xa1, 0x01,     // COLLECTION (Application)
	0x09, 0x01,     //   USAGE (Pointer)
	0xa1, 0x00,     //   COLLECTION (Physical)
	0x09, 0x30,     //     USAGE (X)
	0x09, 0x31,     //     USAGE (Y)
	0x15, 0x81,     //   LOGICAL_MINIMUM (-127)
	0x25, 0x7f,     //   LOGICAL_MAXIMUM (127)
	0x75, 0x08,     //   REPORT_SIZE (8)
	0x95, 0x02,     //   REPORT_COUNT (2)
	0x81, 0x02,     //   INPUT (Data,Var,Abs)
	0xc0,           // END_COLLECTION
	0x05, 0x09,     // USAGE_PAGE (Button)
	0x19, 0x01,     //   USAGE_MINIMUM (Button 1)
	0x29, 0x10,     //   USAGE_MAXIMUM (Button 8)
	0x15, 0x00,     //   LOGICAL_MINIMUM (0)
	0x25, 0x01,     //   LOGICAL_MAXIMUM (1)
	0x75, 0x01,     // REPORT_SIZE (1)
	0x95, 0x10,     // REPORT_COUNT (8)
	0x81, 0x02,     // INPUT (Data,Var,Abs)
	0xc0            // END_COLLECTION
};
*/
__code uint8_t ReportDesc[] ={
0x06,0x00,0xFF,          //Usage Page (unk)
  0x09,0x01,             //Usage (0x01)
  0xA1,0x01,             //Collection (Application)
  0x19,0x01,             //  Usage Minimum (1)
  0x29,0x08,             //  Usage Maximum (8)
  0x15,0x00,             //  Logical Minimum (0)
  0x26,0xFF,0x00,         //   Logical Maximum (255)
  0x75,0x08,              // Report Size (8)
  0x95,0x08,             //  Report Count (8)
  0x81,0x02,             //  Input (Var)
  0x19,0x01,             //  Usage Minimum (1)
  0x29,0x08,             //  Usage Maximum (8)
0x91,0x02
,0xc0};             //  Output (Var)

__code uint16_t CfgDescLen = sizeof(CfgDesc);

//String Descriptors
__code uint8_t LangDes[]={0x04,0x03,0x09,0x04};           //Language Descriptor
__code uint16_t LangDesLen = sizeof(LangDes);
__code uint8_t SerDes[]={                                 //Serial String Descriptor
    0x14,0x03,
    'C',0x00,'H',0x00,'8',0x00,'0',0x00,'5',0x00,'5',0x00
};
__code uint16_t SerDesLen = sizeof(SerDes);
__code uint8_t Prod_Des[]={                                //Produce String Descriptor
    0x16,0x03,
    'C',0x00,'H',0x00,'8',0x00,'0',0x00,'5',0x00,'5',0x00
};
__code uint16_t Prod_DesLen = sizeof(Prod_Des);

__code uint8_t Manuf_Des[]={
    0x0E,0x03,
    'D',0x00,'e',0x00,'q',0x00,'i',0x00,'n',0x00,'g',0x00,
};
__code uint16_t Manuf_DesLen = sizeof(Manuf_Des);
