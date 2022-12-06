class ListOfTasks { 
public: 
	// code omitted for brevity 
	virtual std::string getTask() = 0; 
}; 

  
class Task : public ListOfTasks { 
public:  
	// code omitted for brevity 
	std::string getTask(); 
private: 
	std::string taskDescription; 
}; 
  

class Project : public ListOfTasks { 
public: 
	// code omitted for brevity 
	std::string getTask(); 

private: 
	std::string projectName; 
	std::vector<ListOfTasks*> tasks; 
}; 
