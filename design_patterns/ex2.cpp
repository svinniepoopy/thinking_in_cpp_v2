/*
 * Starting with SingletonPattern.cpp, create a class that provides a connection
 * to a service that stores and retrieves data from a configuration file.
 */

#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <memory>

template<typename T>
class Singleton {
  public:
    // because T inherits from this, its copy constructor is deleted 
    // so we return a reference to a statically construected T;
    static T& Instance() {
      static T t;
      return t;
    }
  protected:
    Singleton() {}
    virtual ~Singleton() {}
  private:
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
};

class Config : public Singleton<Config> {
  public:
    const std::string& Data() {
      return conf;
    }

    void SetConfig(const std::string& val) {
      conf += val;
    }
  private:
    std::string conf;
};


class Service {
  public:
    Service():config{Config::Instance()} {}
    const std::string& GetConfig() {
      return config.Data();
    }

    void SetConfig(const std::string& val) {
      config.SetConfig(val);
    }
  private:
    Config& config;
};


class Connection {
  public:
    Connection() {}

    void operator()(int i) {
      id = i;
      svc->SetConfig("conn: " + std::to_string(id)); 
    }
  private:
    int id;
    std::unique_ptr<Service> svc = std::make_unique<Service>(); 
};

int main() {
  std::vector<std::thread> connections;
  // create 10 connection instances, add something to the config
  for (int i=0;i<100;++i) {
    connections.push_back(std::thread(Connection{}, i));
  }
  for (auto& t:connections) {
    t.join();
  }

  Service svc;
  std::cout << svc.GetConfig() << '\n';

  return 0;
}
