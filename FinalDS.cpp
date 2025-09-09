#include<iostream>
#include <iomanip>  
using namespace std;

#define INF 9999999
#define V 7

int bindex = 0;
int path[V];
int main();
  
string city[V] = {"Islamabad", "Multan", "Faislabad", "Lahore", "Khan Pur", "Quetta", "Karachi"};

// Passenger record
struct record{
	string name;
	string phone_no;
	string cnic;
	string source;
	string destination;
	int seat_no;
	int charges;
	record* next = NULL;
};
void Deletion(string cnic);
void insert(string name, string phone_no, string cnic, string destination, string source, int seat_no, int charges, int bus_serial_number);
void display();

struct pri{
	int age;
	string complain;
	pri* next;
};

void enqueue_Complain(int age, string complain);
void dequeue_Complain();
void display_complains();

// BST
struct bus_tree{
	int serial_no;
	string bus_number;
	string driver_name;
	string cnic;
	string phone_no;
	int bus_fair;
	int height;
	
	bus_tree* left = NULL;
	bus_tree* right = NULL;
	bool seats[30];
	string names[30];
	
	int G[V][V] = {
  	{0, 9, 75, 0, 23, 0, 12},
  	{9, 0, 95, 19, 32, 4, 67},
  	{75, 95, 0, 51, 23, 5, 0},
  	{0, 19, 51, 0, 12, 34, 0},
  	{23, 0, 23, 5, 0, 3, 6},
  	{0, 4, 5, 34, 3, 0, 0},
  	{12, 67, 0, 0, 6, 0, 0}};
	
	record *record_start = NULL;
	record *record_end = NULL;
	
	pri *complains_front = NULL;
	pri *complains_rear = NULL;
};

bus_tree* root = NULL;


int getbf(bus_tree* p);
int gethight(bus_tree* p);
bus_tree* leftR(bus_tree* p);
bus_tree* rightR(bus_tree* p);
bus_tree* insert(bus_tree* r, int ser_no, string bus_no, string name, string cnic, string phone_no ,int fair);
bus_tree* creat(int key);
void pre_order(bus_tree* p);

void deletion(int x);

// Priority

class Graph{
public:
	
	Graph(){
		
	}
	
	void prims_algo(int G[V][V]){
	int no_edge = 0;  
  	bool selected[V];
  
  	for (int i = 0; i<V; i++){
  		selected[i] = false;
  	}

  	selected[0] = true;

  	int x,y;  

  	cout << endl << "--------------------------" << endl;
  	while (no_edge < V - 1) {

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    cout << city[x] << " - " << city[y] << " :  " << G[x][y];
    cout << endl << "--------------------------" << endl;
    selected[y] = true;
    no_edge++;
 	 	}

	}	


	int minDistance(int dist[], bool sptSet[])
	{

		int min = INT_MAX, min_index;

		for (int v = 0; v < V; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;		

				return min_index;
		}

	void printSolution(int dist[],string des)
	{
		cout <<"Vertex \t Distance from Source" << endl << "--------------------------" << endl;
		int j = 0;
		int k;
	
		while (j!=V-1 && city[path[j]] != des){
			int k = path[j];
			cout << city[k] << " -> ";
			j++;
		}
//		if (int k = path[j] == path[0]){
//			cout << " \n total cost: "<<dist[k]<< endl << "--------------------------" << endl;
//		}
//		else{
			k = path[j];
			cout << city[k] << " \n total cost: "<<dist[k]<< endl << "--------------------------" << endl;
//			}
		}

	void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    cout << " -> " << city[j];
}


	void dijkstra(int graph[V][V], int src, int dest) {
	    int dist[V];
	    bool sptSet[V];
	    int parent[V];
	
	    // Initialize distances, visited array and parent array
	    for (int i = 0; i < V; i++) {
	        dist[i] = INT_MAX;
	        sptSet[i] = false;
	        parent[i] = -1;
	    }
	
	    dist[src] = 0;
	
	    for (int count = 0; count < V - 1; count++) {
	        int u = minDistance(dist, sptSet);
	        sptSet[u] = true;
	
	        for (int v = 0; v < V; v++) {
	            if (!sptSet[v] && graph[u][v] && 
	                dist[u] != INT_MAX && 
	                dist[u] + graph[u][v] < dist[v]) {
	                dist[v] = dist[u] + graph[u][v];
	                parent[v] = u;
	            }
	        }
	    }
	
	    // Print the path and total distance
	    cout << "\nShortest Route Details:" << endl;
	    cout << "===================" << endl;
	    cout << "Route: " << city[src];
	    printPath(parent, dest);
	    cout << "\nTotal Distance: " << dist[dest] << " km" << endl;
	    cout << "===================" << endl;
	}};

class BST{
	public:
	
		// Insertion

		
		bus_tree* insert(bus_tree* r, int ser_no, string bus_no, string name, string cnic, string phone_no ,int fair){
			//pre_order(r);
		
			if( r == NULL){
				return creat(ser_no, bus_no, name, cnic, phone_no, fair);
			}
			else if(ser_no < r->serial_no){
				r->left = insert(r->left, ser_no, bus_no, name, cnic, phone_no, fair);
			}
			else if(ser_no > r->serial_no){
				r->right = insert(r->right, ser_no, bus_no, name, cnic, phone_no, fair);
			}
			
			r->height = 1 + max(getheight(r->left), getheight(r->right));
			int bf = getbf(r);
			
			if(bf > 1 && ser_no < r->left->serial_no){
				return rightR(r);
			}
		
			if(bf < -1 && ser_no > r->right->serial_no){
				return leftR(r);         
			}
		
			if(bf > 1 && ser_no > r->left->serial_no){
				r->left = leftR(r->left);
				return rightR(r);
			}
		
			if(bf < -1 && ser_no < r->right->serial_no){
				r->right = rightR(r->right);
				return leftR(r);
			}
		
			return r;
		}
		//Traversal
		void pre_order(bus_tree* p){

    if (p != NULL) {
        cout << "Bus " << p->serial_no << " data: | bus serial number: " << p->serial_no
             << " | bus fare: " << p->bus_fair
             << " | bus number: " << p->bus_number
             << " | driver name: " << p->driver_name
             << " | driver CNIC: " << p->cnic
             << " | driver phone number: " << p->phone_no
             << endl << "--------------------------" << endl;
        pre_order(p->left);
        pre_order(p->right);
    }

}


		
		
		
		void in_order(bus_tree* p){
		    if(p!=NULL){
		    	in_order(p->left);
		        cout<<p->serial_no<<"   ";
		        in_order(p->right);
		    }
		}
		
		
		int getheight(bus_tree* p){
		   int h = 0;
		   if (p != NULL) {
		      int l_height = getheight(p->left);
		      int r_height = getheight(p->right);
		      int max_height = max(l_height, r_height);
		      h = max_height + 1;
		   }
		   return h;
		}
		
		int getbf(bus_tree* p){
		   int l_height = getheight(p->left);
		   int r_height = getheight(p->right);
		   int b_factor = l_height - r_height;
		   return b_factor;
		}
		
		
		
		bus_tree* rightR(bus_tree* p){
			bus_tree* x = p->left;
			bus_tree* k = x->right;
			
			x->right = p;
			p->left = k;
			
			
			p->height = 1 + max(getheight(p->left), getheight(p->right));
			x->height = 1 + max(getheight(p->left), getheight(p->right));
			//pre_order(x);
			return x;
		}
		
		
		
		bus_tree* leftR(bus_tree* p){
			bus_tree* x = p->right;
			bus_tree* k = x->left;
			
			x->left = p;
			p->right = k;
			
			
			p->height = 1 + max(getheight(p->left), getheight(p->right));
			x->height = 1 + max(getheight(p->left), getheight(p->right));
			//pre_order(x);
			return x;
			
		}
		
		bus_tree* creat(int ser_no, string bus_no, string name, string cnic, string phone_no ,int fair){
			bus_tree* ptr = new bus_tree();
			ptr->serial_no = ser_no;
			ptr->bus_fair = fair;
			ptr->bus_number = bus_no;
			ptr->driver_name = name;
			ptr->phone_no = phone_no;
			ptr->cnic = cnic;
		
			
			ptr->left = NULL;
			ptr->right = NULL;
			ptr->height = 1;
			
			return ptr;
		}
		
		
		// Add this function to the BST class
		bus_tree* findMin(bus_tree* node) {
		    bus_tree* current = node;
		    while (current && current->left != NULL) {
		        current = current->left;
		    }
		    return current;
		}
		
		bus_tree* deleteNode(bus_tree* root, int serial_no) {
		    if (root == NULL) {
		        return root;
		    }
		
		    // Find the node to delete
		    if (serial_no < root->serial_no) {
		        root->left = deleteNode(root->left, serial_no);
		    }
		    else if (serial_no > root->serial_no) {
		        root->right = deleteNode(root->right, serial_no);
		    }
		    else {
		        // Node with only one child or no child
		        if (root->left == NULL) {
		            bus_tree* temp = root->right;
		            delete root;
		            return temp;
		        }
		        else if (root->right == NULL) {
		            bus_tree* temp = root->left;
		            delete root;
		            return temp;
		        }
		
		        // Node with two children
		        bus_tree* temp = findMin(root->right);
		        root->serial_no = temp->serial_no;
		        root->bus_number = temp->bus_number;
		        root->driver_name = temp->driver_name;
		        root->cnic = temp->cnic;
		        root->phone_no = temp->phone_no;
		        root->bus_fair = temp->bus_fair;
		        root->right = deleteNode(root->right, temp->serial_no);
		    }
		    return root;
		}
		
		// Add this as a public method in the BST class
		void deleteBus(int serial_no) {
		    bus_tree* result = search(serial_no);
		    if (result == NULL) {
		        cout << "Bus with serial number " << serial_no << " not found." << endl;
		        return;
		    }
		    root = deleteNode(root, serial_no);
		    cout << "Bus with serial number " << serial_no << " has been deleted." << endl;
		}



 		
		
				
		bus_tree* search(int bus_serial_number){
			bus_tree *p = root;
		
			while (p->serial_no != bus_serial_number && p!=NULL){
				if (bus_serial_number > p->serial_no){
					p = p->right;
				}
				else{
					p = p->left;
				}
			}
			
			return p;
		}
				
		void bookSeats(int seat, int bus_serial_number) {
		    bus_tree* bus = search(bus_serial_number);
		    Graph g;
		
		    if (!bus) {
		        cout << "Bus with serial number " << bus_serial_number << " not found.\n";
		        return;
		    }
		
		    if (seat < 1 || seat > 30) {
		        cout << "Invalid seat number. Please choose between 1 and 30.\n";
		        return;
		    }
		
		    if (bus->seats[seat - 1]) {
		        cout << "Seat " << seat << " is already reserved.\n";
		        return;
		    }
		
		    string passenger_name;
		    cout << "Enter passenger name: ";
		    cin.ignore();
		    getline(cin, passenger_name);
		    
		    cout << "\nAvailable Cities:\n";
		    cout << "================\n";
		    for (int i = 0; i < V; i++) {
		        cout << i + 1 << ". " << city[i] << "\n";
		    }
		    
		    int srcIndex, destIndex;
		    cout << "\nEnter source city number (1-7): ";
		    cin >> srcIndex;
		    
		    if (srcIndex < 1 || srcIndex > V) {
		        cout << "Invalid source city number.\n";
		        return;
		    }
		    
		    cout << "Enter destination city number (1-7): ";
		    cin >> destIndex;
		    
		    if (destIndex < 1 || destIndex > V || destIndex == srcIndex) {
		        cout << "Invalid destination city number or same as source.\n";
		        return;
		    }
		
		    // Book the seat
		    bus->seats[seat - 1] = true;
		    bus->names[seat - 1] = passenger_name;
		
		    cout << "\nBooking Summary:\n";
		    cout << "===============\n";
		    cout << "Passenger Name: " << passenger_name << "\n";
		    cout << "Seat Number: " << seat << "\n";
		    cout << "From: " << city[srcIndex - 1] << "\n";
		    cout << "To: " << city[destIndex - 1] << "\n";
		
		    // Calculate and display route
		    g.dijkstra(bus->G, srcIndex - 1, destIndex - 1);
		}
				
		
		void cancel_booking(int seat, int bus_serial_number) {
		    bus_tree* bus = search(bus_serial_number);
		    if (bus == NULL) {
		        cout << "Bus with serial number " << bus_serial_number << " not found." << endl;
		        return;
		    }
		
		    if (seat < 1 || seat > 30) {
		        cout << "Invalid seat number. Please choose between 1 and 30." << endl;
		        return;
		    }
		
		    if (!bus->seats[seat - 1]) {
		        cout << "Seat " << seat << " is not currently booked." << endl;
		        return;
		    }
		
		    cout << "Enter passenger name to confirm cancellation: ";
		    string name;
		    cin.ignore();
		    getline(cin, name);
		
		    if (bus->names[seat - 1] != name) {
		        cout << "Name does not match booking record. Cancellation denied." << endl;
		        return;
		    }
		
		    // Cancel the booking
		    bus->seats[seat - 1] = false;
		    bus->names[seat - 1] = "";
		    
		    cout << "\nBooking Cancellation Summary:" << endl;
		    cout << "==========================" << endl;
		    cout << "Passenger Name: " << name << endl;
		    cout << "Seat Number: " << seat << endl;
		    cout << "Status: Booking Successfully Cancelled" << endl;
		    cout << "==========================" << endl;
		}

		
		void show_booking(string password, int bus_serial_number) {
		    // Check admin password
		    if (password != "1234") {
		        cout << "Invalid admin password. Access denied." << endl;
		        return;
		    }
		
		    bus_tree* bus = search(bus_serial_number);
		    if (bus == NULL) {
		        cout << "Bus with serial number " << bus_serial_number << " not found." << endl;
		        return;
		    }
		
		    bool hasBookings = false;
		    cout << "\nCurrent Bookings for Bus " << bus->bus_number << ":" << endl;
		    cout << "================================" << endl;
		    cout << "Seat No. | Passenger Name" << endl;
		    cout << "--------------------------------" << endl;
		
		    for (int i = 0; i < 30; i++) {
		        if (bus->seats[i]) {
		            hasBookings = true;
		            cout << setw(8) << i + 1 << " | " << bus->names[i] << endl;
		        }
		    }
		
		    if (!hasBookings) {
		        cout << "No current bookings for this bus." << endl;
		    }
		    
		    cout << "================================" << endl;
		}

	};


// CLass for Priority
// Updated Pri class implementation
class Pri {
public:
    Pri() {}
    BST t;
    
    void enqueue_Complain(int age, int bus_serial_number) {
        bus_tree *bus = t.search(bus_serial_number);
        if(bus == NULL) {
            cout << "Bus not registered" << endl << "--------------------------" << endl;
            return;
        }
        
        string complain;
        cout << "Enter complaint: ";
        cin.ignore(); // Clear input buffer
        getline(cin, complain); // Allow multi-word complaints
        
        pri *newcomplain = new pri;
        newcomplain->age = age;
        newcomplain->complain = complain;
        newcomplain->next = NULL; // Initialize next pointer
        
        // If queue is empty
        if (bus->complains_front == NULL) {
            bus->complains_front = bus->complains_rear = newcomplain;
        }
        // If new complaint has higher priority (older age)
        else if (age >= bus->complains_front->age) {
            newcomplain->next = bus->complains_front;
            bus->complains_front = newcomplain;
        }
        // If new complaint has lowest priority
        else if (age < bus->complains_rear->age) {
            bus->complains_rear->next = newcomplain;
            bus->complains_rear = newcomplain;
        }
        // Insert in middle based on priority
        else {
            pri *current = bus->complains_front;
            pri *prev = NULL;
            
            while (current != NULL && age < current->age) {
                prev = current;
                current = current->next;
            }
            
            newcomplain->next = current;
            prev->next = newcomplain;
        }
        
        cout << "Complaint Successfully Submitted" << endl << "--------------------------" << endl;
    }
    
    void dequeue_Complain(int bus_serial_number) {
        bus_tree *bus = t.search(bus_serial_number);
        if(bus == NULL) {
            cout << "Bus not registered" << endl << "--------------------------" << endl;
            return;
        }
        
        if(bus->complains_front == NULL) {
            cout << "No complaints registered" << endl << "--------------------------" << endl;
            return;
        }
        
        pri* temp = bus->complains_front;
        bus->complains_front = bus->complains_front->next;
        
        // If queue becomes empty after dequeue
        if(bus->complains_front == NULL) {
            bus->complains_rear = NULL;
        }
        
        cout << "Resolved Complaint Details:" << endl;
        cout << "--------------------------" << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Complaint: " << temp->complain << endl;
        cout << "--------------------------" << endl;
        
        delete temp;
    }
    
    void display_complains(int bus_serial_number) {
        bus_tree *bus = t.search(bus_serial_number);
        
        if (bus == NULL) {
            cout << "Bus not registered" << endl << "--------------------------" << endl;
            return;
        }
        
        if(bus->complains_front == NULL) {
            cout << "No complaints registered" << endl << "--------------------------" << endl;
            return;
        }
        
        cout << "All Registered Complaints:" << endl;
        cout << "--------------------------" << endl;
        pri* current = bus->complains_front;
        int count = 1;
        
        while(current != NULL) {
            cout << "Complaint #" << count << endl;
            cout << "Age: " << current->age << endl;
            cout << "Details: " << current->complain << endl;
            cout << "--------------------------" << endl;
            current = current->next;
            count++;
        }
    }
};


class Record{
	
	public:
		BST t;
		void insert(string name, string phone_no, string cnic, string destination, string source, int seat_no, int charges, int bus_serial_number){
			bus_tree *bus = t.search(bus_serial_number);
			
			if (bus == NULL){
				cout<<"Bus not registered"<<endl << "--------------------------" << endl;
			}
			
			else{
				record* p = new record();
				p->name = name;
				p->phone_no = phone_no;
				p->cnic = cnic;
				p->destination = destination;
				p->source = source;
				p->seat_no = seat_no;
				p->charges = charges;
			
				if(bus->record_start == NULL){
					bus->record_start = bus->record_end = p;
				}
				else{
					bus->record_end->next = p;
					bus->record_end = p;
				}
			}
			
			cout << "Record added" << endl << "--------------------------" << endl;
		}
		
		void deletion(int bus_serial_number){
			bus_tree *bus = t.search(bus_serial_number);
			
			if(bus == NULL){
				cout<<"Bus not registered"<<endl << "--------------------------" << endl;
			}
			
			else{
				string cnic;
				cout<<"enter your cnic"<<endl << "--------------------------" << endl;
				cin>>cnic;
				record* p = bus->record_start;
				record* k;
			
				while(p != NULL && p->cnic != cnic){
					k = p;
					p = p->next;
				}
			
				if(p == NULL){
					cout << "Record not found" << endl << "--------------------------" << endl;
				}
				else{
					if(p == bus->record_start){
						bus->record_start = bus->record_start->next;
					}
					else if(p == bus->record_end){
						bus->record_end = k;
					}
					else{
						k->next = p->next;
					}
				}
			}
			
			cout << "Record deleted" << endl << "--------------------------" << endl;
		}
		void display(int bus_serial_number){
			bus_tree *bus = t.search(bus_serial_number);
			
			if(bus == NULL){
				cout<<"Bus not registered"<<endl << "--------------------------" << endl;
			}
			else{
				record* p = bus->record_start;
			
				while(p != NULL){
					cout << p->name << " ";
					cout << p->phone_no << " ";
					cout << p->cnic << " ";
					cout << p->source << " ";
					cout << p->destination << " ";
					cout << p->seat_no << " ";
					cout << p->charges << " ";
				
					cout << endl << "--------------------------" << endl;
				
					p = p->next;
					}
				}
			}
			
};



// Updated main function with new menu option
int main() {
    BST t;
    Pri p;
    Record r;
    int choice, choice1;

    while (true) {
        cout << "\n================ BUS RESERVATION SYSTEM ================\n";
        cout << "1. Bus Management\n";
        cout << "2. Seat Reservation\n";
        cout << "3. Complaints Management\n";
        cout << "4. Passenger Records\n";
        cout << "5. Exit\n";
        cout << "=======================================================\n";
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting the system. Thank you!\n";
            break;
        }

        switch (choice) {
            case 1: // Bus Management
                cout << endl;
                cout << "\n--- BUS MANAGEMENT ---\n";
                cout << "1. Register a new bus\n";
                cout << "2. Search for a bus\n";
                cout << "3. Display all buses\n";
                cout << "4. Delete a bus\n";  // New option
                cout << endl;
                cout << "Enter your choice: ";
                cin >> choice1;

                if (choice1 == 1) {
                    int s_no, fair;
                    string bus_no, name, cnic, phone_no;
                    cout << endl;
                    cout << "Enter bus serial number: ";
                    cin >> s_no;
                    cout << "Enter bus fare: ";
                    cin >> fair;
                    cout << "Enter bus number: ";
                    cin >> bus_no;
                    cout << "Enter driver name: ";
                    cin >> name;
                    cout << "Enter driver CNIC: ";
                    cin >> cnic;
                    cout << "Enter driver phone number: ";
                    cin >> phone_no;
                    cout << endl;
                    root = t.insert(root, s_no, bus_no, name, cnic, phone_no, fair);
                } else if (choice1 == 2) {
                    if (!root) {
                        cout << "No buses registered yet.\n";
                    } else {
                        int serial_number;
                        cout << "Enter the serial number of the bus: ";
                        cin >> serial_number;
                        bus_tree* result = t.search(serial_number);
                        if (result) {
                            cout << "Bus found: " << result->bus_number << "\n";
                        } else {
                            cout << "Bus not found.\n";
                        }
                    }
                } else if (choice1 == 3) {
                    if (!root) {
                        cout << "No buses registered yet.\n";
                    } else {
                        cout << "Displaying all registered buses:\n";
                        t.pre_order(root);
                    }
                } else if (choice1 == 4) {  // New case for deletion
                    if (!root) {
                        cout << "No buses registered yet.\n";
                    } else {
                        int serial_number;
                        cout << "Enter the serial number of the bus to delete: ";
                        cin >> serial_number;
                        t.deleteBus(serial_number);
                    }
                } else {
                    cout << "Invalid input. Try again.\n";
                }
                break;

            case 2: // Seat Reservation
			    cout << "\n========== SEAT RESERVATION ==========\n";
			    cout << "1. Book a seat\n";
			    cout << "2. Cancel a booking\n";
			    cout << "3. Display all bookings (Admin)\n";
			    cout << "=====================================\n";
			    cout << "Enter your choice: ";
			    cin >> choice1;
			
			    switch(choice1) {
			        case 1: {
			            if (!root) {
			                cout << "No buses registered yet.\n";
			                break;
			            }
			            int s_no, seat;
			            cout << "\nEnter bus serial number: ";
			            cin >> s_no;
			            cout << "Enter seat number (1-30): ";
			            cin >> seat;
			            t.bookSeats(seat, s_no);
			            break;
			        }
			        case 2: {
			            if (!root) {
			                cout << "No buses registered yet.\n";
			                break;
			            }
			            int s_no, seat;
			            cout << "\nEnter bus serial number: ";
			            cin >> s_no;
			            cout << "Enter seat number (1-30): ";
			            cin >> seat;
			            t.cancel_booking(seat, s_no);
			            break;
			        }
			        case 3: {
			            if (!root) {
			                cout << "No buses registered yet.\n";
			                break;
			            }
			            int s_no;
			            string password;
			            cout << "\nEnter bus serial number: ";
			            cin >> s_no;
			            cout << "Enter admin password: ";
			            cin >> password;
			            t.show_booking(password, s_no);
			            break;
			        }
			        default:
			            cout << "Invalid choice. Please try again.\n";
			    }
			    break;
            case 3: // Complaints Management
             	cout << endl;
                cout << "\n--- COMPLAINTS MANAGEMENT ---\n";
                cout << "1. Register a complaint\n";
                cout << "2. Resolve the first complaint\n";
                cout << "3. Display all complaints\n";
                cout << "Enter your choice: ";
                cin >> choice1;
                cout << endl;

                if (choice1 == 1) {
                    int s_no, age;
                    cout << "Enter bus serial number: ";
                    cin >> s_no;
                    cout << "Enter your age: ";
                    cin >> age;
                    p.enqueue_Complain(age, s_no);
                } else if (choice1 == 2) {
                    int s_no;
                    cout << "Enter bus serial number: ";
                    cin >> s_no;
                    p.dequeue_Complain(s_no);
                } else if (choice1 == 3) {
                    int s_no;
                    cout << "Enter bus serial number: ";
                    cin >> s_no;
                    p.display_complains(s_no);
                } else {
                    cout << "Invalid input. Try again.\n";
                }
                break;

            case 4: // Passenger Records
             	cout << endl;
                cout << "\n--- PASSENGER RECORDS ---\n";
                cout << "1. Add passenger record\n";
                cout << "2. Delete passenger record\n";
                cout << "3. Display all passenger records\n";
                cout << "Enter your choice: ";
                cin >> choice1;
                cout << endl;

                if (choice1 == 1) {
                    string name, phone_no, source, destination, cnic;
                    int seat_no, charges, s_no;
                    cout << "Enter passenger name: ";
                    cin >> name;
                    cout << "Enter CNIC: ";
                    cin >> cnic;
                    cout << "Enter phone number: ";
                    cin >> phone_no;
                    cout << "Enter source city: ";
                    cin >> source;
                    cout << "Enter destination city: ";
                    cin >> destination;
                    cout << "Enter seat number: ";
                    cin >> seat_no;
                    cout << "Enter charges: ";
                    cin >> charges;
                    cout << "Enter bus serial number: ";
                    cin >> s_no;
                    r.insert(name, phone_no, cnic, destination, source, seat_no, charges, s_no);
                } else if (choice1 == 2) {
                    int s_no;
                    cout << "Enter bus serial number: ";
                    cin >> s_no;
                    r.deletion(s_no);
                } else if (choice1 == 3) {
                    int s_no;
                    cout << "Enter bus serial number: ";
                    cin >> s_no;
                    r.display(s_no);
                } else {
                    cout << "Invalid input. Try again.\n";
                }
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
