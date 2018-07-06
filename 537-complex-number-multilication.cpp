class Solution {
public:
    class Complex {
    private:
        int _real;
        int _img;
    public:
        Complex(int real, int img) : _real(real), _img(img) {}
        static Complex FromString(const string& str) {
            int pos = str.find("+");
            int real = stoi(str.substr(0, pos));
            int img = stoi(str.substr(pos+1, str.length()-pos-2));
            return Complex(real, img);
        }
        Complex Multiply(const Complex& rhs) {
            int real = _real * rhs._real - _img * rhs._img;
            int img = _real * rhs._img + _img * rhs._real;
            return Complex(real, img);
        }
        string ToString() const {
            return to_string(_real) + "+" + to_string(_img) + "i";
        }
    };
    string complexNumberMultiply(string a, string b) {
        Complex ca = Complex::FromString(a);
        Complex cb = Complex::FromString(b);
        Complex ans = ca.Multiply(cb);
        return ans.ToString();
    }
};