#include "rotx.hh"

#include <iostream>

void RotX::process()
{
    int len = this->input_.length();
    for (int i = 0; i < len; i++)
    {
        int cpkey = key_;
        if (this->input_[i] <= '9' && this->input_[i] >= '0')
        {
            if (cpkey < 0)
            {
                while (cpkey <= 0)
                {
                    cpkey += 10;
                }
            }
            auto num = this->input_[i] - '0';
            auto num2 = (num + cpkey) % 10;
            auto num3 = num2 + '0';
            this->input_[i] = num3;
        }
        else if (this->input_[i] <= 'Z' && this->input_[i] >= 'A')
        {
            if (cpkey < 0)
            {
                while (cpkey <= 0)
                {
                    cpkey += 26;
                }
            }
            auto num = this->input_[i] - 'A';
            auto num2 = (num + cpkey) % 26;
            auto num3 = num2 + 'A';
            this->input_[i] = num3;
        }
        else if (this->input_[i] <= 'z' && this->input_[i] >= 'a')
        {
            if (cpkey < 0)
            {
                while (cpkey <= 0)
                {
                    cpkey += 26;
                }
            }
            auto num = this->input_[i] - 'a';
            auto num2 = (num + cpkey) % 26;
            auto num3 = num2 + 'a';
            this->input_[i] = num3;
        }
    }

    std::cout << this->input_ << '\n';
}