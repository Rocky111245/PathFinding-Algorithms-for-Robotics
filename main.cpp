#include <iostream>
#include <utility>
#include <unordered_set>
#include <memory>
#include <set>
#include <vector>
#include <iomanip>

// Vertex structure
struct Adjacency_List_Head {
    std::string name_of_vertex;
    std::unique_ptr<std::unordered_set<std::string>> link;

    Adjacency_List_Head(const std::string& name)
            : name_of_vertex(name), link(nullptr) {}
};


// Custom comparator for sorting Vertex by name_of_vertex in std::set
struct CompareVertex {
    bool operator()(const Adjacency_List_Head& v1, const Adjacency_List_Head& v2) const {
        return v1.name_of_vertex < v2.name_of_vertex; // Sort alphabetically by name_of_vertex
    }
};



// Hash function for Vertex (required for unordered_set)
struct VertexHash {
    std::size_t operator()(const Adjacency_List_Head& v) const {
        return std::hash<std::string>{}(v.name_of_vertex);
    }
};






struct Adjacency_List_Tail{
    std::string name_of_vertex;
    int distance_from_node;

    Adjacency_List_Tail(const std::string& name, int distance_from_node)
            : name_of_vertex(name), distance_from_node(distance_from_node) {}



    //overloaded operator
    bool operator==(const Adjacency_List_Tail& other) const{
        return name_of_vertex==other.name_of_vertex;
    };

};

// Custom comparator for sorting Vertex by name_of_vertex in std::set
struct CompareTail {
    bool operator()(const Adjacency_List_Tail& v1, const Adjacency_List_Tail& v2) const {
        return v1.name_of_vertex < v2.name_of_vertex; // Sort alphabetically by name_of_vertex
    }
};


int total_number_of_states;
// Declare a set of Vertex using the custom comparator for sorting vertices
std::set<Adjacency_List_Head, CompareVertex> vertex_heads;

std::unordered_set<Adjacency_List_Tail,CompareTail> vertex_tails;

std::vector<std::unordered_set<Adjacency_List_Tail,CompareTail>> tails(total_number_of_states);


void Form_Head(const size_t &number_of_states) {
    for (size_t i = 0; i < number_of_states; i++) {
        std::string state_name;
        std::cout << "Please enter name for state " << i << ": ";
        std::cin >> state_name;

        // Directly emplace a new Adjacency_List_Head object
        auto [inserted_it, success] = vertex_heads.emplace(state_name);

        if (success) {
            std::cout << "State '" << state_name << "' added.\n";
        } else {
            std::cout << "State '" << state_name << "' already exists.\n";
            i--;
        }
        if(inserted_it->link== nullptr){
            std::cout << "Pointer is null. \n";
        }
    }
}

void Form_Tails(){

    
}

void Display_Heads() {
    std::cout << "+-----------------------------+----------+\n";
    std::cout << "| Head name (State)           | Link     |\n";
    std::cout << "+-----------------------------+----------+\n";

    // Iterate over each Adjacency_List_Head object in the set
    for (const auto& head : vertex_heads) {
        std::cout << "| " << std::left << std::setw(27) << head.name_of_vertex << " | ";

        // Check if the link pointer is null or not
        if (head.link == nullptr) {
            std::cout << "nullptr  |\n";
        } else {
            std::cout << "not null |\n";
        }
    }

    std::cout << "+-----------------------------+----------+\n";
}








//suppose 10 states. This means
// 1) 10 heads
// 2) 10 lists
// 3)



int main() {

    Form_Head(5);
    Display_Heads();

    return 0;
}
