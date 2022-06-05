#include "CmdWrapper.h"
#include <stddef.h>
#include <assert.h>
#include <string.h>

static eCmdStatus_t cmdAddHandler(const void* const pInData, const void* pOutData);
static eCmdStatus_t cmdMulHandler(const void* const pInData, const void* pOutData);

static const fp_CmdHandle gc_CmdHandlerTable[E_CMD_MAX] = 
{
    [E_CMD_NONE] = NULL,
    [E_CMD_ADD] = cmdAddHandler,
    [E_CMD_MUL] = cmdMulHandler,

};


static eCmdStatus_t cmdAddHandler(const void* const pInData, const void* pOutData)
{
    eCmdStatus_t status = E_FAILURE;
    sCmdAddData_t tempData = {0};

    memcpy(&tempData,(const sCmdAddData_t*)pInData, sizeof(sCmdAddData_t));
    tempData.Res = tempData.Add1 + tempData.Add2 ; 
    memcpy((sCmdAddData_t*)pOutData,&tempData, sizeof(sCmdAddData_t));

}

static eCmdStatus_t cmdMulHandler(const void* const pInData, const void* pOutData)
{
    eCmdStatus_t status = E_FAILURE;
    sCmdTMulData_t tempData = {0};

    memcpy(&tempData,(const sCmdTMulData_t*)pInData, sizeof(sCmdTMulData_t));
    tempData.Res = tempData.Mul1 * tempData.Mul2 ; 
    memcpy((sCmdTMulData_t*)pOutData,&tempData, sizeof(sCmdTMulData_t));
    
}


eCmdStatus_t CmdHandler(eCmdID_t cmdID, const void* const pInData, const void* pOutData)
{
    assert(cmdID < E_CMD_MAX);

    eCmdStatus_t status = E_CMD_NOT_FOUND;
    status = gc_CmdHandlerTable[cmdID](pInData, pOutData);
    return status;
}
