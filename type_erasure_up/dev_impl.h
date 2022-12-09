#ifndef _TYPE_ERASURE_DEV_IMPL_H_
#define _TYPE_ERASURE_DEV_IMPL_H_

#include <memory>
#include <string>

#include <cstdint>

class TcpPort
{
public:
    explicit TcpPort(std::string ip, uint16_t pn) : ip_{ip}, port_{pn} {}
    ~TcpPort() = default;

    std::string GetIp() const;
    uint16_t GetPort() const;

private:
    std::string ip_;
    uint16_t port_;
};

class SerialPort
{
public:
    explicit SerialPort(std::string dev) : dev_{dev} {}
    ~SerialPort() = default;

    std::string GetDev() const;

private:
    std::string dev_;
};

// class Port
// {
// private:
//     struct Concept {
//         virtual ~Concept() {}
//         virtual void do_read(std::string& buf) const = 0;
//         virtual void do_write(std::string const& buf) const = 0;
//         virtual void do_stat() const = 0;
//     };

//     template<typename T>
//     struct Model: Concept {
//         Model(T const& value) : object{value} {}
//         void do_read(std::string& buf) const override { read(object, buf); }

//         void do_write(std::string const& buf) const override
//         {
//             do_write(object, buf);
//         }
//         void do_stat() const override { stat(object); }
//         T object;
//     };

//     std::unique_ptr<Concept> pimpl;

//     friend void read(Port& port, std::string& v) { port.pimpl->do_read(v); }

//     friend void write(Port& port, std::string const& q)
//     {
//         port.pimpl->do_write(q);
//     }

//     friend void stat(Port const& port) { port.pimpl->do_stat(); }

// public:
//     template<typename T>
//     Port(T const& x) : pimpl{new Model<T>(x)}
//     {
//     }
//     // Special member functions
//     Port(Port const& s);
//     Port(Port&& s);
//     Port& operator=(Port const& s);
//     Port& operator=(Port&& s);
// };

#endif