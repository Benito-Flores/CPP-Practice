#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    // prompt user input for side a, side b, and angle A(in degrees)
    double sidea, sideb, angleADeg;
    cout << "enter side a, side b, and angle A(in degrees)\n";
    cin >> sidea >> sideb >> angleADeg;
    
    // convert angle A from degrees to radians
    const double PI = 3.141592653589793;
    double angleARad = (PI / 180) * angleADeg;
    
    // get sinB
    double sinB = (sideb * sin(angleARad)) / sidea;
    
    // get measurement of angle B in radians
    double angleBRad = asin(sinB);
    
    // convert angle B from radians to degrees
    double angleBDeg = (180 / PI) * angleBRad;
    
    // get angle C
    double angleCDeg = 180 - angleADeg - angleBDeg;
    
    //calculate ambiguous angles
    double ambAngleBDeg = 180 - angleBDeg; // ambiguous angle B
    double ambAngleCDeg = 180 - ambAngleBDeg - angleADeg; // ambiguous angle C
    
    // logical function for SSA and The Ambiguous Case
    if (angleADeg < 90 && sidea < sideb) {
        if (sidea < sideb * sin(angleARad)) {
            cout << "No solution\n";
        } else if (abs(sidea - sideb * sin(angleARad)) < 0.0001) {
            cout << "Angle B = " << angleBDeg << " degrees" << endl;
            cout << "Angle C = " << angleCDeg << " degrees" <<  endl;
        } else if (sideb > sidea && sidea > sideb * sin(angleARad)) {
            cout << "Angle B = " << angleBDeg << " degrees" <<  endl;
            cout << "Angle C = " << angleCDeg << " degrees" <<  endl;
            cout << "OR\n";
            cout << "Angle B = " << ambAngleBDeg << " degrees" <<  endl;
            cout << "Angle C = " << ambAngleCDeg << " degrees" <<  endl;
        }
    } else if (angleADeg < 90 && sidea >= sideb) {
        cout << "Angle B = " << angleBDeg << " degrees" <<  endl;
        cout << "Angle C = " << angleCDeg << " degrees" <<  endl;
    } else if (angleADeg > 90 || angleADeg == 90) {
        if (sidea <= sideb) {
            cout << "No solution\n";
        } else if (sidea > sideb) {
            cout << "Angle B = " << angleBDeg << " degrees" <<  endl;
            cout << "Angle C = " << angleCDeg << " degrees" <<  endl;
        }
    }
    
    return 0;
}
