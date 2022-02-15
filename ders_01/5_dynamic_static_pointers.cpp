
int* ptr;	// global pointer, hence static ptr is initialized to NULL on program start

int main() {

	int* ptr2;			// local (dynamic) pointer ptr2 has indetermined or garbage value
	static int* ptr3;	// static pointer ptr3 is initialized to NULL on program start
}
