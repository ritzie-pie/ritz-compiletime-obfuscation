/*
 * MIT License https://github.com/ritzie-pie/ritz-compiletime-obfuscation/blob/main/LICENSE
 *
 * Copyright (c) 2024 ritzie-pie
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef RITZ_OBF_HPP
#define RITZ_OBF_HPP

#include <iostream>

#define RITZ_OBF_ENDL ; \
{ \
    int a = 1, b = 2, c = 3; \
    for (int i = 0; i < 10; ++i) { a += b; b += c; c += a; } \
    double d = 0.1, e = 0.2, f = 0.3; \
    for (int i = 0; i < 10; ++i) { d += e; e += f; f += d; } \
    char g = 'a', h = 'b', i = 'c'; \
    for (int j = 0; j < 10; ++j) { g += h; h += i; i += g; } \
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; \
    for (int j = 0; j < 10; ++j) { arr[j] = arr[(j+1)%10] + arr[(j+2)%10]; } \
    if (a != b) { a = c; } \
    if (b != c) { b = d; } \
    if (c != d) { c = e; } \
    if (d != e) { d = f; } \
    if (e != f) { e = g; } \
    if (f != g) { f = h; } \
    if (g != h) { g = i; } \
    for (int k = 0; k < 50; ++k) { \
        a += b; b += c; c += d; d += e; e += f; f += g; g += h; h += i; i += a; \
    } \
    uintptr_t x = 0x12345678; \
    if (x != 0) { x += 0x87654321; } \
    for (int k = 0; k < 50; ++k) { \
        x ^= a; a ^= x; x ^= a; \
    } \
    double arr2[10]; \
    for (int j = 0; j < 10; ++j) { arr2[j] = arr2[(j+1)%10] * 1.5; } \
    float y = 1.2345f; \
    for (int k = 0; k < 50; ++k) { \
        y += (a != 0 ? a : 1); y *= (b != 0 ? b : 1); y -= (c != 0 ? c : 1); \
        y /= (d != 0 ? d : 1); \
    } \
    int j = 0; \
    while (j < 100) { j++; a = (a * (b != 0 ? b : 1)) % (c != 0 ? c : 1); } \
    void* ptr = &a; \
    if (ptr != nullptr) { ptr = &b; } \
    int k = 0; \
    for (int l = 0; l < 50; ++l) { k = (k * (l != 0 ? l : 1)) + j; j = (l != 0 ? k % l : 0); } \
    { int a = 123, b = 456, c = 789; a = b + c; b = a - c; c = a * b; } \
    { double a = 1.23, b = 4.56, c = 7.89; a = b / (c != 0 ? c : 1); b = c * a; c = a + b; } \
    { float a = 1.1f, b = 2.2f, c = 3.3f; a = b - c; b = (c != 0 ? c / a : 1); c = a * b; } \
    { char a = 'a', b = 'b', c = 'c'; a += b; b += c; c += a; } \
    { uintptr_t a = 0x123, b = 0x456, c = 0x789; a = b + c; b = a - c; c = a * b; } \
    { int a = 1, b = 2, c = 3; a += b; b += c; c += a; } \
    { double a = 0.1, b = 0.2, c = 0.3; a += b; b += c; c += a; } \
    { char a = 'a', b = 'b', c = 'c'; a += b; b += c; c += a; } \
    { int arr[10]; for (int j = 0; j < 10; ++j) { arr[j] = arr[(j+1)%10] + arr[(j+2)%10]; } } \
    { if (a != b) { a = c; } if (b != c) { b = d; } if (c != d) { c = e; } if (d != e) { d = f; } } \
    { if (e != f) { e = g; } if (f != g) { f = h; } if (g != h) { g = i; } if (h != i) { h = a; } } \
    { for (int k = 0; k < 50; ++k) { a += b; b += c; c += d; d += e; e += f; f += g; g += h; h += i; i += a; } } \
    { uintptr_t x = 0x12345678; if (x != 0) { x += 0x87654321; } } \
    { for (int k = 0; k < 50; ++k) { x ^= a; a ^= x; x ^= a; } } \
    { double arr2[10]; for (int j = 0; j < 10; ++j) { arr2[j] = arr2[(j+1)%10] * 1.5; } } \
    { float y = 1.2345f; for (int k = 0; k < 50; ++k) { y += (a != 0 ? a : 1); y *= (b != 0 ? b : 1); y -= (c != 0 ? c : 1); y /= (d != 0 ? d : 1); } } \
    { int j = 0; while (j < 100) { j++; a = (a * (b != 0 ? b : 1)) % (c != 0 ? c : 1); } } \
    { void* ptr = &a; if (ptr != nullptr) { ptr = &b; } } \
    { int k = 0; for (int l = 0; l < 50; ++l) { k = (k * (l != 0 ? l : 1)) + j; j = (l != 0 ? k % l : 0); } } \
    { int a = 123, b = 456, c = 789; a = b + c; b = a - c; c = a * b; } \
    { double a = 1.23, b = 4.56, c = 7.89; a = b / (c != 0 ? c : 1); b = c * a; c = a + b; } \
    { float a = 1.1f, b = 2.2f, c = 3.3f; a = b - c; b = (c != 0 ? c / a : 1); c = a * b; } \
    { char a = 'a', b = 'b', c = 'c'; a += b; b += c; c += a; } \
    { uintptr_t a = 0x123, b = 0x456, c = 0x789; a = b + c; b = a - c; c = a * b; } \
    { int a = 1, b = 2, c = 3; a += b; b += c; c += a; } \
    { double a = 0.1, b = 0.2, c = 0.3; a += b; b += c; c += a; } \
    { char a = 'a', b = 'b', c = 'c'; a += b; b += c; c += a; } \
    { int arr[10]; for (int j = 0; j < 10; ++j) { arr[j] = arr[(j+1)%10] + arr[(j+2)%10]; } } \
    { if (a != b) { a = c; } if (b != c) { b = d; } if (c != d) { c = e; } if (d != e) { d = f; } } \
    { if (e != f) { e = g; } if (f != g) { f = h; } if (g != h) { g = i; } if (h != i) { h = a; } } \
    { for (int k = 0; k < 50; ++k) { a += b; b += c; c += d; d += e; e += f; f += g; g += h; h += i; i += a; } } \
    { uintptr_t x = 0x12345678; if (x != 0) { x += 0x87654321; } } \
    { for (int k = 0; k < 50; ++k) { x ^= a; a ^= x; x ^= a; } } \
    { double arr2[10]; for (int j = 0; j < 10; ++j) { arr2[j] = arr2[(j+1)%10] * 1.5; } } \
    { float y = 1.2345f; for (int k = 0; k < 50; ++k) { y += (a != 0 ? a : 1); y *= (b != 0 ? b : 1); y -= (c != 0 ? c : 1); y /= (d != 0 ? d : 1); } } \
    { int j = 0; while (j < 100) { j++; a = (a * (b != 0 ? b : 1)) % (c != 0 ? c : 1); } } \
    { void* ptr = &a; if (ptr != nullptr) { ptr = &b; } } \
    { int k = 0; for (int l = 0; l < 50; ++l) { k = (k * (l != 0 ? l : 1)) + j; j = (l != 0 ? k % l : 0); } } \
}

#endif // include guard
