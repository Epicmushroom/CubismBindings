/*
 * Copyright(c) Live2D Inc. All rights reserved.
 * 
 * Use of this source code is governed by the Live2D Open Software license
 * that can be found at http://live2d.com/eula/live2d-open-software-license-agreement_en.html.
 */


/* {{{autogeneratedwarning}}} */


#include <Live2DCubismCore.h>


// -------- //
// REQUIRES //
// -------- //

#include <stdlib.h>
#include <string.h>


// ------- //
// HELPERS //
// ------- //

void* csmMallocMoc(const unsigned int size)
{
    void* memory;


    posix_memalign(&memory, csmAlignofMoc, size);


    return memory;
}


csmModel* csmMallocModelAndInitialize(const csmMoc* moc)
{
    unsigned int size;
    csmModel *model;
    void *memory;


    if (!moc)
    {
        return 0;
    }


    size = csmGetSizeofModel(moc);
    

    if (posix_memalign(&memory, csmAlignofModel, size))
    {
        return 0;
    }


    model = csmInitializeModelInPlace(moc, memory, size);


    if (!model)
    {
        free(memory);
    }


    return model;
}


void csmFree(void *memory)
{
    free(memory);
}