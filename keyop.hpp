#pragma once

class Key {
  bool status; // if push, status = true

public:
  Key() {
    status = false;
  }

  void setStatusPush() {
    status = true;
  }

  void setStatusRelease() {
    status = false;
  }

  bool getStatus() {
    return status;
  }
};