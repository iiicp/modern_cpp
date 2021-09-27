class OldCallBack {
public:
  /// typedef void(*DataCallBack)(char *data, int len);
  using DataCallBack = void(*)(char *data, int len);

  OldCallBack () {
    m_cb = nullptr;
  }

  void set_callback(DataCallBack cb) {
    m_cb = cb;
  }
  void send_callback() {
    if (m_cb) {
      m_cb(nullptr, 1024);
    }
  }
private:
  DataCallBack m_cb;
};


class NewCallBack{
public:
  /// 使用std::function包装函数，可传入 lambda, function object, member function...
  using DataCallBack = std::function<void(char *data, int len)>;

  NewCallBack () {
    m_cb = nullptr;
  }
  void set_callback(const DataCallBack &cb) {
    m_cb = cb;
  }
  void send_callback() {
    if (m_cb) {
      m_cb(nullptr, 1024);
    }
  }
  void member_func(char *data, int len) {
    std::cout << "new style: member func" << std::endl;
  }
private:
  DataCallBack m_cb;
};