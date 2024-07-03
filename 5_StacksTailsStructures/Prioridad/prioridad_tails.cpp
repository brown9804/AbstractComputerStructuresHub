#include "header.h"


using namespace std;

#define Data Element<int>

int main(int argc, char **argv){

	srand(time(0));

	int cant_tails = 0;
	cant_tails = atoi(argv[1]);
 	int full_tails = cant_tails;
	Queue<Data> tails [cant_tails];
	int cap_tails[cant_tails];
	int prioridad_tails[cant_tails];

	for(int i = 0; i < (cant_tails*2 - 1); i += 2){
		if(argv[2][i] != ':'){
			prioridad_tails[i/2] = ((int)argv[2][i] - 13);
		}
	}

	for(int i = 0; i < cant_tails; i++){
		cap_tails[i] = (rand() % 19) + 4;
	}

	for (int j = 0; j < cant_tails; j++){
		for (int i = 0; i < cap_tails[j]; i++){
			tails[j].enqueue((rand() % 24) + 5);
		}
	}

	for (int i = 0; i < cant_tails; i++){
		cout << "Tail # " << i+1 << ": ";
		tails[i].imprimir_cola();
	}



	cout <<"Output: ";
	while(full_tails > 0){
		full_tails = cant_tails;
		for (int j = 0; j < cant_tails; j++){
			if(!tails[j].empty()){
				for (int i = 0; i < prioridad_tails[j]; i++){
					Data e = tails[j].dequeue();
			        if (e.isValid())
			        {
			            cout << e.get() << " ";
			        }
				}

			}
			else{
				full_tails --;
			}
		}

	}
	cout << endl;

}
