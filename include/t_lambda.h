#ifndef T_LAMBDA_H
#define T_LAMBDA_H

#include <iostream>

using namespace std;

class T_lambda
{
public:
    static int test() {
        auto sum = [](int n)->int {
            int s = 0;
            for(int k=1; k<=n; k++) { s+=k; }
            return s;
        };

        cout << "Summary 7 = " << sum(7) << endl;

        // l'identifiant du type de retour peuvent être omis puisque le type est défini par la valeur retournée
        auto fact=[](int n) {
            int f=1;
            for(int k=1; k<=n; k++)
                f*=k;
            return f;
        };
        cout << "Factorial 7 = " << fact(7);

        return 0;
    }
};

#endif // T_LAMBDA_H
