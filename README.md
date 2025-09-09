# Bus Reservation System
A comprehensive bus reservation management system implemented in C++ that demonstrates the practical application of multiple data structures and algorithms.

## Overview
This system provides a complete solution for managing bus reservations, including bus registration, seat booking, complaint handling, and passenger record management. It features route optimization using graph algorithms and efficient data management through various data structures.

## Features
### 🚍 Bus Management
- Register new buses with complete driver and vehicle details
- Search for buses by serial number
- Display all registered buses
- Delete buses from the system
- Self-balancing AVL tree for efficient bus data storage
### Seat Reservation
- Book seats (1-30 per bus) with passenger information
- Cancel bookings with name verification
- Admin panel to view all bookings (password protected)
- Real-time route calculation using Dijkstra's algorithm
- Interactive city selection with distance optimization
### Complaints Management
- Priority-based complaint system (age-based prioritization)
- Register complaints with automatic priority assignment
- Resolve complaints in priority order (elderly first)
- Display all pending complaints
### Passenger Records
- Comprehensive passenger information storage
- Add detailed passenger records
- Delete records by CNIC verification
- Display all passenger records for specific buses

## Technical Architecture
### Data Structures Implemented
| Data Structure | Usage | Complexity |
|---------------|-------|------------|
| **AVL Tree** | Bus storage and management | O(log n) search/insert/delete |
| **Priority Queue** | Age-based complaint handling | O(log n) enqueue/dequeue |
| **Linked List** | Passenger records storage | O(n) traversal |
| **Graph (Adjacency Matrix)** | City network representation | O(V²) space |
| **Arrays** | Seat booking status | O(1) access |

### Algorithms Used
- **Dijkstra's Algorithm**: Shortest path calculation between cities
- **Prim's Algorithm**: Minimum spanning tree for city connections
- **AVL Tree Rotations**: Automatic tree balancing
- **Priority Queue Operations**: Age-based prioritization

## 🗺️ Supported Cities
The system includes 7 major Pakistani cities with interconnected routes:
1. **Islamabad** - Capital city
2. **Multan** - Historic city
3. **Faisalabad** - Industrial hub
4. **Lahore** - Cultural capital
5. **Khan Pur** - Regional center
6. **Quetta** - Provincial capital
7. **Karachi** - Commercial metropolis

## Getting Started
### Prerequisites
- C++ compiler (GCC 7.0+ or equivalent)
- Standard C++ libraries
- Terminal/Command prompt
### Compilation
```bash
g++ -o bus_reservation main.cpp -std=c++11
```
### Running the Application
```bash
./bus_reservation
```

## Usage Guide
### Main Menu Options
```
1. Bus Management
2. Seat Reservation  
3. Complaints Management
4. Passenger Records
5. Exit
```
### Bus Management
1. **Register Bus**: Enter serial number, fare, bus number, and driver details
2. **Search Bus**: Find bus by serial number
3. **Display All**: View all registered buses
4. **Delete Bus**: Remove bus from system
### Seat Reservation
1. **Book Seat**: 
   - Enter bus serial number
   - Choose seat (1-30)
   - Provide passenger details
   - Select source and destination cities
   - View optimized route and distance
2. **Cancel Booking**:
   - Enter bus serial number and seat number
   - Verify with passenger name
3. **View Bookings** (Admin only):
   - Password: `1234`
   - View all current bookings for a bus
### Complaints Management
1. **Register Complaint**: Enter bus serial number, age, and complaint details
2. **Resolve Complaint**: Process complaints in priority order (elderly first)
3. **View Complaints**: Display all pending complaints
### Passenger Records
1. **Add Record**: Store complete passenger information
2. **Delete Record**: Remove record by CNIC verification
3. **Display Records**: View all passenger records for a bus

## System Configuration
### Default Settings
- **Seats per bus**: 30
- **Admin password**: 1234
- **Cities supported**: 7
- **Maximum distance**: Calculated via Dijkstra's algorithm
### Memory Management
- Dynamic memory allocation for all data structures
- Proper deallocation to prevent memory leaks
- Efficient space utilization through balanced trees

## Security Features
- **Admin Authentication**: Password protection for sensitive operations
- **Data Validation**: Input verification for all user entries
- **Access Control**: Restricted access to booking information
- **CNIC Verification**: Secure record deletion process

## Error Handling
The system includes comprehensive error handling for:
- Invalid bus serial numbers
- Seat availability conflicts
- Incorrect passenger information
- Invalid city selections
- Memory allocation failures
- Authentication errors

## Performance Characteristics
| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Bus Search | O(log n) | O(1) |
| Seat Booking | O(log n) | O(1) |
| Route Calculation | O(V²) | O(V) |
| Complaint Processing | O(log n) | O(n) |
| Record Management | O(n) | O(n) |

## Example Usage
### Booking a Seat
1. Choose "Seat Reservation" → "Book a seat"
2. Enter bus serial number: `101`
3. Enter seat number: `15`
4. Enter passenger name: `John Doe`
5. Select source city: `1` (Islamabad)
6. Select destination: `4` (Lahore)
7. System calculates optimal route and displays booking summary
### Managing Complaints
1. Choose "Complaints Management" → "Register a complaint"
2. Enter bus serial number: `101`
3. Enter age: `65` (gets higher priority)
4. Enter complaint: "Air conditioning not working"
5. System queues complaint based on age priority

## Contributing
This project demonstrates various data structures and algorithms concepts. Feel free to extend the functionality by:
- Adding more cities to the network
- Implementing additional algorithms
- Enhancing the user interface
- Adding data persistence features

## 📝 Code Structure
```
├── Bus Management (AVL Tree)
├── Seat Reservation (Arrays + Graph Algorithms)
├── Complaints System (Priority Queue)
├── Passenger Records (Linked List)
├── Graph Algorithms (Dijkstra, Prim's)
└── Main Interface (Menu-driven system)
```
## Group Members
- Ayesha Mansoor
- Dania Taj
- Naqiya Ezzy
- Sakina Abbas
## Learning Outcomes
This project demonstrates:
- **Data Structure Implementation**: AVL trees, priority queues, linked lists
- **Algorithm Application**: Graph algorithms, tree balancing
- **Object-Oriented Programming**: Class design and encapsulation
- **Memory Management**: Dynamic allocation and deallocation
- **User Interface Design**: Menu-driven console application
- **Error Handling**: Robust input validation and error management

## License
This project is created for educational purposes and demonstrates the practical implementation of data structures and algorithms in a real-world scenario.
---

**Note**: This system is designed for educational purposes and demonstrates various computer science concepts through practical implementation.
