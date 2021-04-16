#include <iostream>

int fn_GetMax(int* ip_Arr, int i_Size);
void fn_CountingSort(int* ip_IA, int* ip_OA, int i_Size, int i_Exp);
void fn_Radixsort(int* ip_IA, int* ip_OA, int i_Size);

int main(){
	int ia_IArr[]   = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int i_Size      = sizeof(ia_IArr) / sizeof(int);
	int* ip_2Arr    = new int[i_Size]{};

	fn_Radixsort(ia_IArr, ip_2Arr, i_Size);

	for(int i_Ct = 0; i_Ct < i_Size; i_Ct++){
        std::cout<< ip_2Arr[i_Ct] << " ";
	}
	delete []  ip_2Arr;
	return 0;
}

int fn_GetMax(int* ip_Arr, int i_Size){
	int i_Max       = ip_Arr[0];
	for (int i_Ct= 1; i_Ct < i_Size; i_Ct++)
		if (ip_Arr[i_Ct] > i_Max)
			i_Max = ip_Arr[i_Ct];
	return i_Max;
}

void fn_CountingSort(int* ip_IA, int* ip_OA, int i_Size, int i_Exp){
	// COM:  digits in decimal presentation are ten.
	int* ip_CtArr=      new int[10]{};

	for (int i_Ct= 0; i_Ct < i_Size; i_Ct++){
		ip_CtArr[(ip_IA[i_Ct] / i_Exp) % 10]++;
	}

	for (int i_Ct= 1; i_Ct < 10; i_Ct++){
		ip_CtArr[i_Ct] += ip_CtArr[i_Ct - 1];
	}

	for (int i_Ct = i_Size - 1; i_Ct >= 0; i_Ct--) {
		ip_OA[(--(
                  ip_CtArr[(ip_IA[i_Ct] / i_Exp) % 10]
                 )
              )]
                                                = ip_IA[i_Ct];
	}

	for (int i_Ct = 0; i_Ct < i_Size; i_Ct++){
		ip_IA[i_Ct] = ip_OA[i_Ct];
	}
    delete [] ip_CtArr;
}

void fn_Radixsort(int* ip_IA, int* ip_OA, int i_Size){
	// COM: Finding the Max value in the array
	int i_Max = fn_GetMax(ip_IA, i_Size);

	for (int i_Exp = 1; i_Max / i_Exp > 0; i_Exp *= 10){
        fn_CountingSort(ip_IA, ip_OA, i_Size, i_Exp);
	}
}
