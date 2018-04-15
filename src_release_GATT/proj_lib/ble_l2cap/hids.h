
#pragma once

#include "../../proj/tl_common.h"
#include "service.h"

/** @addtogroup  
 *  @{
 */

/** @addtogroup  SERVICE_MODULE Service
 *  @{
 */


/** @addtogroup  HIDS_Module Hids
 *  @{
 */
 
/** @addtogroup  Hids_Constant Hids Constants
 *  @{
 */

/**
 *  @brief  Definition for Characteristics UUID
 */

/** @addtogroup hids_uuid Hids Charactersitc UUID
 * @{
 */

#define CHARACTERISTIC_UUID_HID_BOOT_KEY_INPUT          0x2A22    //!< HID Boot Keyboard Input Report
#define CHARACTERISTIC_UUID_HID_BOOT_KEY_OUTPUT         0x2A32    //!< HID Boot Keyboard Output Report
#define CHARACTERISTIC_UUID_HID_BOOT_MOUSE_INPUT        0x2A33    //!< HID Boot Mouse Input Report
#define CHARACTERISTIC_UUID_HID_INFORMATION             0x2A4A    //!< HID Information
#define CHARACTERISTIC_UUID_HID_REPORT_MAP              0x2A4B    //!< HID Report Map
#define CHARACTERISTIC_UUID_HID_CONTROL_POINT           0x2A4C    //!< HID Control Point
#define CHARACTERISTIC_UUID_HID_REPORT                  0x2A4D    //!< HID Report
#define CHARACTERISTIC_UUID_HID_PROTOCOL_MODE           0x2A4E    //!< HID Protocol Mode

/** @} end of group hids_uuid */


/** @addtogroup  HID_REPORT_ID Hid Report Id
 *  @{
 */

/**
 *  @brief  HID Report ID
 */


/** @} end of group HID_REPORT_ID */


/** @addtogroup  HID_REPORT_TYPE Hid Report Type
 *  @{
 */

/**
 *  @brief  HID Report type
 */

#define HID_REPORT_TYPE_INPUT                           1
#define HID_REPORT_TYPE_OUTPUT                          2
#define HID_REPORT_TYPE_FEATURE                         3

/** @} end of group HID_REPORT_TYPE */


/** @addtogroup  HID_PROTOCOL_MODE Hid Protocol Mode
 *  @{
 */

/**
 *  @brief  Definition for HID protocol mode
 */
#define HID_PROTOCOL_MODE_BOOT                          0
#define HID_PROTOCOL_MODE_REPORT                        1
#define DFLT_HID_PROTOCOL_MODE                          HID_PROTOCOL_MODE_REPORT

/** @} end of group HID_PROTOCOL_MODE */


/** @addtogroup  HID_INFOR_FLAGS Hid Information Flags
 *  @{
 */
/**
 *  @brief  Definition for HID information flags
 */
#define HID_FLAGS_REMOTE_WAKE                           0x01      // RemoteWake
#define HID_FLAGS_NORMALLY_CONNECTABLE                  0x02      // NormallyConnectable

/** @} end of group HID_INFOR_FLAGS */

#define HID_KEYCODE_CC_RELEASE                          0x00
#define HID_KEYCODE_CC_VOL_UP                           0x01
#define HID_KEYCODE_CC_VOL_DN                           0x02


/** @} end of group Hids_Constant */




/** @addtogroup  Hids_Callbacks Hids Callbacks
 *  @{
 */

/**
 *  @brief  Definition argutment type of report change callback function
 */
typedef struct {
    u8 id;
    u8 type;
    u8 len;
    u8 value[1];
} reportChange_t;

/**
 *  @brief  Definition argutment type of CCC change callback function
 */
typedef struct {
    u8 id;
    u8 type;
    u8 value;
} clientCharCfgChange_t;

/**
 *  @brief  Definition client characterist configuration of report changed callback function type for user application
 */
typedef void (*hids_clientCharCfgChangeCb_t)(clientCharCfgChange_t* cccVal);

/**
 *  @brief  Definition report value changed callback function type for user application
 */
typedef void (*hids_reportChangeCb_t)(reportChange_t* reportVal);

/**
 *  @brief  Definition report value changed callback function type for user application
 */
typedef void (*hids_protoModeChangeCb_t)(u32 protoMode);

/**
 *  @brief  Definition report value changed callback function type for user application
 */
typedef void (*hids_ctrlPointChangeCb_t)(u32 ctrlPoint);

/**
 *  @brief  Definition for foundation command callbacks.
 */
typedef struct {
    hids_reportChangeCb_t         reportChangeCbFunc;     //!< report value changed callback function
    hids_protoModeChangeCb_t      protoModeChangeCbFunc;  //!< protocol mode value changed callback function
    hids_ctrlPointChangeCb_t      ctrlPointChangeCbFunc;  //!< control point value changed callback function
    hids_clientCharCfgChangeCb_t  cccChangedCbFunc;       //!< ccc of report changed callback function
} hids_callbacks_t;

/** @} end of group Hids_Callbacks */


 /** @addtogroup  HIDS_Variables  Hids Variables
 *  @{
 */
 
 /**
 *  @brief  External variable for HID service Attribute tables
 */
extern attribute_t hid_attrTbl[];

/**
 *  @brief  External variable for HID service attribute size
 */
extern u16         hid_attrSize;

/**
 *  @brief  External variable for HID information
 */
extern const u8    hidInformation[];

/** @} end of group HIDS_Variables */


/** @addtogroup  HIDS_Functions Hids APIs
 *  @{
 */

/**
 * @brief       API to add HID service to gatt.
 *
 * @param[in]   hidsCb - The callback function of HID service
 *
 * @return      Status
 */
ble_sts_t hids_addService(hids_callbacks_t* hidsCb);

ble_sts_t hids_keyInReport(u16 connHandle, u8* value, u8 len);

ble_sts_t hids_consumerControlInReport(u16 connHandle, u8* value, u8 len);

/** @} end of group HIDS_Functions */

/** @} end of group HIDS_Module */

/** @} end of group SERVICE_MODULE */

