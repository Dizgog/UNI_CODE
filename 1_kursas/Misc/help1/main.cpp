#include <iostream>
#include <iostream>

using namespace std;

int z = 0,f = 0;

unsigned int getSum(int data[], int n){
    unsigned int sum = 0;
    for(int i = 0; i < n; i += 1){
            sum += data[i];
   z++;
    }
    return sum;
}
int main() {
    int data[] = { 1, 2, 3, 4, 5 };
    cout << getSum(data, 5) << z << endl;
    return 0;
}

// O(N)
// ciklas ir palygina eina 5 kartus, prideda  kartus
//
