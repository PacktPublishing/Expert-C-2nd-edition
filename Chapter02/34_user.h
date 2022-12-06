class User { 
public: 
// constructors and assignment operators are omitted for code brevity 
	void set_name(const std::string& name); 
	std::string get_name() const; 
	void set_email(const std::string&); 
	std::string get_email() const; 
// more setters and getters are omitted for code brevity 
private: 
	std::string name_; 
	std::string email_; 
	Address address_; 
	int age; 
}; 
