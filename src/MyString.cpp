// Copyright 2020 GHA created by Klykov Anton

#include "MyString.h"

MyString::MyString(const char* _str) {
    if (_str == nullptr) {
        _string = nullptr;
        _length = 0;
    } else {
        size_t i = 0;
        size_t length_str = 0;
        while (_str[i] != '\0') {
            length_str++;
            i++;
        }
        _string = new char[length_str + 1];
        _length = length_str;
        i = 0;
        for (; i < _length; ++i) {
            _string[i] = _str[i];
        }
        _string[i] = '\0';
    }
}

MyString::MyString(std::string _str) {
    _length = _str.size();
    _string = new char[_length + 1];
    size_t i = 0;
    for (; i < _length; ++i) {
        _string[i] = _str[i];
    }
    _string[i] = '\0';
}

MyString::MyString(const MyString& _str) {
    this->_length = _str._length;
    this->_string = new char[_length + 1];
    size_t i = 0;
    for (; i < this->_length; ++i) {
        _string[i] = _str._string[i];
    }
    _string[i] = '\0';
}

MyString::MyString(MyString&& _str)  noexcept {
    _string = _str._string;
    _length = _str._length;
    _str._string = nullptr;
    _str._length = 0;
}

MyString::~MyString() {
    delete [] _string;
    _string = nullptr;
}

unsigned int MyString::length() {
    return _length;
}

char* MyString::get() {
    return _string;
}

MyString MyString::operator+(const MyString& _str) {
        MyString _temporary;
        _temporary._length = this->length() + _str._length;
        _temporary._string = new char[_temporary._length + 1];
        size_t i = 0;
        if (_string != nullptr) {
            while (this->_string[i] != '\0') {
                _temporary._string[i] = this->_string[i];
                i++;
            }
        }
        if (_str._string != nullptr) {
            size_t k{0};
            while (_str._string[k] != '\0') {
                _temporary._string[i] = _str._string[k];
                k++;
                i++;
            }
        }
        _temporary._string[_temporary._length] = '\0';
        return _temporary;
}

MyString MyString::operator-(const MyString& _str) {
    MyString _temporary;
    static size_t i{0};
    static size_t j{0};
    for (int i = 0; i < _str._length; ++i) {
        for (int j = 0; j < _length; ++j) {
            if (_string[j] == _str._string[i]) {
                _temporary._length++;
                break;
            }
        }
    }
    size_t k{0};
    size_t ind{0};
    _temporary._string = new char[_length - _temporary._length + 1];
    for (size_t i = 0; i < _length; ++i) {
        for (size_t j = 0; j < _temporary._length; ++j) {
            if (_string[i] == _str._string[j]) {
                ind++;
                break;
            }
        }
        if (ind == 0) {
            _temporary._string[k] = _string[i];
            k++;
        }
        ind = 0;
    }
    _temporary._string[_length - _temporary._length] = '\0';
    return _temporary;
}

MyString MyString::operator*(int val) {
    MyString _temporary(*this);
    for (size_t i = 0; i < val - 1; ++i) {
        _temporary = *this + _temporary;
    }
    return _temporary;
}

MyString& MyString::operator=(const MyString& _str) {
    if (&_str == this) {
        return *this;
    } else if (_str._string == nullptr) {
        _length = 0;
        _string = nullptr;
        return *this;
    }
    this->_length = _str._length;
    this->_string = new char[length() + 1];
    size_t i = 0;
    for (; i < this->_length; ++i) {
        _string[i] = _str._string[i];
    }
    _string[i] = '\0';
    return *this;
}

MyString& MyString::operator=(MyString&& _str) {
    if (&_str == this) {
        return *this;
    }
    delete [] _string;
    _string = _str._string;
    _length = _str._length;
    _str._string = nullptr;
    _str._length = 0;
    return *this;
}

bool MyString::operator==(const MyString& _str) {
    if (length() != _str._length) {
        return false;
    }
    for (size_t i = 0; i < length(); ++i) {
        if (_string[i] != _str._string[i]) {
            return false;
        }
    }
    return true;
}

bool MyString::operator!=(const MyString& _str) {
    if (length() != _str._length) {
        return true;
    }
    for (size_t i = 0; i < length(); ++i) {
        if (_string[i] != _str._string[i]) {
            return true;
        }
    }
    return false;
}

bool MyString::operator>(const MyString& _str) {
    size_t min{0};
    min = (length() > _str._length) ? _str._length : length();
    size_t i{0};
    while (i < min) {
        if (_string[i] == _str._string[i]) {
            continue;
        } else if (_string[i] > _str._string[i]) {
            return true;
        } else {
            return false;
        }
        i++;
    }
    return false;
}

bool MyString::operator<(const MyString& _str) {
    size_t min{0};
    min = (length() > _str._length) ? _str._length : length();
    size_t i{0};
    while (i < min) {
        if (_string[i] == _str._string[i]) {
            continue;
        } else if (_string[i] < _str._string[i]) {
            return true;
        } else {
            return false;
        }
        i++;
    }
    return false;
}

bool MyString::operator>=(const MyString& _str) {
    size_t min{0};
    min = (length() > _str._length) ? _str._length : length();
    size_t i{0};
    while (i < min) {
        if (_string[i] == _str._string[i]) {
            continue;
        } else if (_string[i] > _str._string[i]) {
            return true;
        } else {
            return false;
        }
        i++;
    }
    return true;
}

bool MyString::operator<=(const MyString& _str) {
    size_t min{0};
    min = (length() > _str._length) ? _str._length : length();
    size_t i{0};
    while (i < min) {
        if (_string[i] == _str._string[i]) {
            continue;
        } else if (_string[i] < _str._string[i]) {
            return true;
        } else {
            return false;
        }
        i++;
    }
    return true;
}

MyString MyString::operator!() {
    MyString _temporary;
    _temporary._length = _length;
    _temporary._string = new char[_length + 1];
    for (size_t i = 0; i < _length; ++i) {
        if (_string[i] <= 122 && _string[i] >= 97) {
            _temporary._string[i] -= 32;
        } else if (_string[i] <= 90 && _string[i] >= 65) {
            _temporary._string[i] += 32;
        }
    }
    _temporary._string[_length] = '\0';
    return _temporary;
}

char& MyString::operator[](const int val) {
    return _string[val];
}

int MyString::operator()(const char* _str) {
    size_t i{0};
    static size_t j{0};
    size_t k{0};
    while (_str[i] != '\0') {
        for (; j < _length; ++j) {
            if (_string[j] == _str[i]) {
                k++;
                break;
            }
        }
        if (k == i) {
            return -1;
        }
        i++;
    }
    return 0;
}

std::ostream& operator<<(std::ostream& out, MyString& _str) {
    return out << _str.get();
}

std::istream& operator>>(std::istream& in, MyString& _str) {
    std::string _temp;
    in >> _temp;
    _str = MyString(_temp);
    return in;
}
