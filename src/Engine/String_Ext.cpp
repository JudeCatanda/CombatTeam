#include "String_Ext.hpp"

int String_GetLen(const char* buffer) {
    int _count = 0;
    while(*buffer != 0) {
        char current = *buffer;
        _count++;
        buffer++;
    }
    return _count;
};

void Strings_DFree(struct Strings* strs) {
    for(int i = 0; i < strs->num; i++) {
        free(strs->data[i]);
    }
    free(strs->data);
}

struct Strings String_split(const char* buffer, char delim) {
    char* _buff_temp = (char*)malloc(1);
    int itr = 0;
    int splited_len = 0;
    struct Strings _temp = {
        .data = NULL,
        .num = 0,
    };
    while(*buffer != 0) {
        char current = *buffer;

        if(current != delim) {
            splited_len += 1;
            _buff_temp = (char*)realloc(_buff_temp, splited_len + 1);
            _buff_temp[itr++] = current;
        } else {
            _buff_temp[itr] = 0;
            _temp.data = (char**)realloc(_temp.data, sizeof(char*) * (_temp.num + 1));
            _temp.data[_temp.num] = (char*)malloc(String_GetLen(_buff_temp) + 1);

            for (int i = 0; i <= String_GetLen(_buff_temp); i++) {
                _temp.data[_temp.num][i] = _buff_temp[i];
            }

            _temp.num++;


            itr = 0;
            splited_len = 0;
            free(_buff_temp);
            _buff_temp = (char*)malloc(1);
        }
        buffer++;

    };

    if (itr > 0) {
        _buff_temp[itr] = 0;
        _temp.data = (char**)realloc(_temp.data, sizeof(char*) * (_temp.num + 1));
        _temp.data[_temp.num] = (char*)malloc(String_GetLen(_buff_temp) + 1);
        for (int i = 0; i <= String_GetLen(_buff_temp); i++) {
            _temp.data[_temp.num][i] = _buff_temp[i];
        }
        _temp.num++;

    }
    return _temp;
};
int String_FindChar(const char* buffer, char chc) {
    int itr = 0;
    while(*buffer != 0) {
        if(*buffer == chc) {
            return itr;
        }
        itr++;
        buffer++;
    }
    return -1;
};
char* String_SubStr(const char* buffer, char starting, char ending) {
    if(buffer == NULL) return NULL;
    int start_index = String_FindChar(buffer, starting);
    if(start_index == -1) return NULL;
    buffer += start_index;

    int end_index = String_FindChar(buffer, ending);
    if(end_index == -1) return NULL;

    char* _temp = (char*)malloc(end_index+ 2);
    if(!_temp) return NULL;

    int _temp_itr = 0;
    for (int i = 0; i <= end_index; i++) {
        _temp[_temp_itr++] = buffer[i];
    }
    _temp[_temp_itr] = 0;
    return _temp;
};
char* String_ToUpperCased(const char* buffer) {
    if(buffer == NULL) return NULL;

    int len = String_GetLen(buffer);
    char* _temp = (char*)malloc(len+1);

    if(!_temp) return NULL;
    for (int i = 0; i <= len; i++) {
        if(buffer[i] >= 'a' && buffer[i] <= 'z') {
            _temp[i] = buffer[i] - 32;
        } else {
            _temp[i] = buffer[i];
        }
    }
    _temp[len] = 0;
    return _temp;
};
char* String_ToLowerCased(const char* buffer) {
    if(buffer == NULL) return NULL;

    int len = String_GetLen(buffer);
    char* _temp = (char*)malloc(len+1);

    if(!_temp) return NULL;
    for (int i = 0; i <= len; i++) {
        if(buffer[i] >= 'A' && buffer[i] <= 'Z') {
            _temp[i] = buffer[i] + 32;
        } else {
            _temp[i] = buffer[i];
        }
    }
    _temp[len] = 0;
    return _temp;
}

