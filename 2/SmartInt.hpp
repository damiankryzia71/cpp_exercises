#include <memory>

class SmartInt
{
    private:
        std::unique_ptr<int> value;
    public:
        SmartInt();
        SmartInt(int);
        int get() const;
        void set(int);
        int operator*() const;
};