/********************************************************************************
*  This file is part of CinoLib                                                 *
*  Copyright(C) 2016: Marco Livesu                                              *
*                                                                               *
*  The MIT License                                                              *
*                                                                               *
*  Permission is hereby granted, free of charge, to any person obtaining a      *
*  copy of this software and associated documentation files (the "Software"),   *
*  to deal in the Software without restriction, including without limitation    *
*  the rights to use, copy, modify, merge, publish, distribute, sublicense,     *
*  and/or sell copies of the Software, and to permit persons to whom the        *
*  Software is furnished to do so, subject to the following conditions:         *
*                                                                               *
*  The above copyright notice and this permission notice shall be included in   *
*  all copies or substantial portions of the Software.                          *
*                                                                               *
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   *
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,     *
*  FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE *
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER       *
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING      *
*  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS *
*  IN THE SOFTWARE.                                                             *
*                                                                               *
*  Author(s):                                                                   *
*                                                                               *
*     Marco Livesu (marco.livesu@gmail.com)                                     *
*     http://pers.ge.imati.cnr.it/livesu/                                       *
*                                                                               *
*     Italian National Research Council (CNR)                                   *
*     Institute for Applied Mathematics and Information Technologies (IMATI)    *
*     Via de Marini, 6                                                          *
*     16149 Genoa,                                                              *
*     Italy                                                                     *
*********************************************************************************/
#include <cinolib/solid_angle.h>
#include <cinolib/pi.h>
#include <cmath>

namespace cinolib
{

// Computes the solid angle of a point p with respect
// to an oriented triangle v0-v1-v2, ad described in:
//
// The solid angle of a plane triangle
// Adriaan Van Oosterom and Jan Strackee
// IEEE transactions on Biomedical Engineering (1983)
//
CINO_INLINE
double solid_angle(const vec3d & v0,
                   const vec3d & v1,
                   const vec3d & v2,
                   const vec3d & p)
{
    vec3d  a   = v0 - p;
    vec3d  b   = v1 - p;
    vec3d  c   = v2 - p;
    double al  = a.norm();
    double bl  = b.norm();
    double cl  = c.norm();
    double ab  = a.dot(b);
    double ac  = a.dot(c);
    double bc  = b.dot(c);
    double det = a.dot(b.cross(c));

    return atan2(det,(al*bl*cl + ab*cl + ac*bl + bc*al))/(2*M_PI);
}

}
