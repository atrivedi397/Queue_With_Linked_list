//
// Created by atrivedi on 3/30/18.
//

#pragma once

class swapping
{
public:
    template<typename T1 , typename T2>
    void swap(T1 *a , T2 *b)
    {
        T2 temp;
        temp = *b;
        *b = T2(*a);
        *a = temp;
    };
};
