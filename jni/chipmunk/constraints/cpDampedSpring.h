/* Copyright (c) 2007 Scott Lembcke
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

struct cpConstraint;

typedef cpFloat (*cpDampedSpringForceFunc)(struct cpConstraint *spring, cpFloat dist);

extern CHIPMUNK_API cpDampedSpringForceFunc cpDampedSpringUpdateForceDefault;

CHIPMUNK_API const cpConstraintClass *cpDampedSpringGetClass();

typedef struct CHIPMUNK_API cpDampedSpring {
	cpConstraint constraint;
	cpVect anchr1, anchr2;
	cpFloat restLength;
	cpFloat stiffness;
	cpFloat damping;
	cpDampedSpringForceFunc springForceFunc;
	
	cpFloat target_vrn;
	cpFloat v_coef;
	
	cpVect r1, r2;
	cpFloat nMass;
	cpVect n;
} cpDampedSpring;

CHIPMUNK_API cpDampedSpring *cpDampedSpringAlloc(void);
CHIPMUNK_API cpDampedSpring *cpDampedSpringInit(cpDampedSpring *joint, cpBody *a, cpBody *b, cpVect anchr1, cpVect anchr2, cpFloat restLength, cpFloat stiffness, cpFloat damping);
CHIPMUNK_API cpConstraint *cpDampedSpringNew(cpBody *a, cpBody *b, cpVect anchr1, cpVect anchr2, cpFloat restLength, cpFloat stiffness, cpFloat damping);

CP_DefineConstraintProperty(cpDampedSpring, cpVect, anchr1, Anchr1);
CP_DefineConstraintProperty(cpDampedSpring, cpVect, anchr2, Anchr2);
CP_DefineConstraintProperty(cpDampedSpring, cpFloat, restLength, RestLength);
CP_DefineConstraintProperty(cpDampedSpring, cpFloat, stiffness, Stiffness);
CP_DefineConstraintProperty(cpDampedSpring, cpFloat, damping, Damping);
CP_DefineConstraintProperty(cpDampedSpring, cpDampedSpringForceFunc, springForceFunc, SpringForceFunc);
