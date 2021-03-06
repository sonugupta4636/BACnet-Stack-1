/**************************************************************************
*
* Copyright (C) 2005 Steve Karg <skarg@users.sourceforge.net>
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
*********************************************************************/
#ifndef MS_INPUT_H
#define MS_INPUT_H

#include <stdbool.h>
#include <stdint.h>
#include "bacdef.h"
#include "bacerror.h"
#include "rp.h"
#include "wp.h"


void Multistate_Input_Property_Lists(
    const BACNET_PROPERTY_ID **pRequired,
    const BACNET_PROPERTY_ID **pOptional,
    const BACNET_PROPERTY_ID **pProprietary);

bool Multistate_Input_Valid_Instance(
    uint32_t object_instance);
unsigned Multistate_Input_Count(
    void);
uint32_t Multistate_Input_Index_To_Instance(
    unsigned index);
unsigned Multistate_Input_Instance_To_Index(
    uint32_t instance);

int Multistate_Input_Read_Property(
    BACNET_READ_PROPERTY_DATA * rpdata);

    bool Multistate_Input_Write_Property(
        BACNET_WRITE_PROPERTY_DATA * wp_data);

/* optional API */
bool Multistate_Input_Object_Instance_Add(
    uint32_t instance);

bool Multistate_Input_Object_Name(
    uint32_t object_instance,
    BACNET_CHARACTER_STRING * object_name);
bool Multistate_Input_Name_Set(
    uint32_t object_instance,
    char *new_name);

uint32_t Multistate_Input_Present_Value(
    uint32_t object_instance);
bool Multistate_Input_Present_Value_Set(
    uint32_t object_instance,
    uint32_t value);

bool Multistate_Input_Change_Of_Value(
    uint32_t instance);
void Multistate_Input_Change_Of_Value_Clear(
    uint32_t instance);
bool Multistate_Input_Encode_Value_List(
    uint32_t object_instance,
    BACNET_PROPERTY_VALUE * value_list);

bool Multistate_Input_Out_Of_Service(
    uint32_t object_instance);
void Multistate_Input_Out_Of_Service_Set(
    uint32_t object_instance,
    bool value);

char *Multistate_Input_Description(
    uint32_t instance);
bool Multistate_Input_Description_Set(
    uint32_t object_instance,
    char *text_string);

BACNET_RELIABILITY Multistate_Input_Reliability(
    uint32_t object_instance);
bool Multistate_Input_Reliability_Set(
    uint32_t object_instance,
    BACNET_RELIABILITY value);

bool Multistate_Input_State_Text_Set(
    uint32_t object_instance,
    uint32_t state_index,
    char *new_name);
bool Multistate_Input_Max_States_Set(
    uint32_t instance,
    uint32_t max_states_requested);
char *Multistate_Input_State_Text(
    uint32_t object_instance,
    uint32_t state_index);

bool Multistate_Input_Create(
    uint32_t object_instance);
bool Multistate_Input_Delete(
    uint32_t object_instance);
void Multistate_Input_Cleanup(
    void);

void Multistate_Input_Init(
    void);


#ifdef TEST
#include "ctest.h"
void testMultistateInput(
    Test * pTest);
#endif

#endif
