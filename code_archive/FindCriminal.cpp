#include <iostream>

using namespace std;

int main()
{
	int A, B, C, D, E, F;
	for (A = 0; A <= 1; A++)
		for (B = 0; B <= 1; B++)
			for (C = 0; C <= 1; C++)
				for (D = 0; D <= 1; D++)
					for (E = 0; E <= 1; E++)
						for (F = 0; F <= 1; F++)
						{
							if ( (A||B)
							&& ((A&&E)||(A&&F)||(E&&F))
							&& (!(A&&D))
							&& ((B&&C)||(!B&&!C))
							&& ((C&&!D)||(!C&&D))
							&& (D||(!D&&!E))
							== 1)
								cout << A << B << C << D << E << F;
						}
	return 0;
}