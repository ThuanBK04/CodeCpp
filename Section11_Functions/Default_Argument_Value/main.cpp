#include <iostream>

using namespace std;

double calc_cost(double base_cost, double rax_rate = 0.06, double shipping = 3.50);

double calc_cost(double base_cost, double tax_rate, double shipping)
{
    return base_cost += (base_cost * tax_rate) + shipping;
}

int main()
{
    double cost {0};
    cost = calc_cost(100.0, 0.08, 4.25); // use no defaults
    cost = calc_cost(100.0, 0.08); // use shipping default
    cost = calc_cost(100.0); // use tax and shipping defaults
	cout << "Default Template!" << endl; 
	return 0;
}
