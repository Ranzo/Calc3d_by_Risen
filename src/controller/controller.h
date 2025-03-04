#pragma once

#include <memory>

#include "../model/facade.h"

class Controller {
 public:
  Controller(const Controller &other) = delete;
  Controller(Controller &&other) = delete;
  void operator=(const Controller &other) = delete;
  ~Controller() = default;

  static std::shared_ptr<Controller> GetInstance() {
    static auto instance = std::shared_ptr<Controller>(new Controller);
    return instance;
  }

 private:
  std::shared_ptr<Facade> facade;

  Controller() { facade_ = s21::Facade::GetInstance(); }
};