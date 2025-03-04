#pragma once

#include <memory>

class Facade {
 public:
  Facade(const Facade &other) = delete;
  Facade(Facade &&other) = delete;
  void operator=(const Facade &other) = delete;
  ~Facade() = default;

  static std::shared_ptr<Facade> GetInstance() {
    static auto instance = std::shared_ptr<Facade>(new Facade);
    return instance;
  }

 private:
  Facade() {}
};