#ifndef CMD_WRAPPER_H
#define CMD_WRAPPER_H

#include <stdint.h>

typedef enum
{
    E_CMD_NONE,
    E_CMD_ADD,
    E_CMD_MUL,
    E_CMD_MAX,
}eCmdID_t;

typedef enum
{
    E_SUCCESS,
    E_FAILURE,
    E_CMD_NOT_FOUND,
}eCmdStatus_t; 

typedef eCmdStatus_t (*fp_CmdHandle)(const void* const pDataIn, const void* pDataOut);


typedef struct
{
    uint8_t Add1;
    uint8_t Add2;
    uint8_t Res;
}sCmdAddData_t;

typedef struct
{
    uint8_t Mul1;
    uint8_t Mul2;
    uint8_t Res;
}sCmdTMulData_t;

eCmdStatus_t CmdHandler(eCmdID_t cmdID, const void* const pInData, const void* pOutData);

#endif