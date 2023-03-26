#ifndef RECHNER_H
#define RECHNER_H


class Rechner {
    public:
        int plus(int num, ...) {
            va_list arg;
            va_start(arg, num);

            int result = 0;
            for(int i=0;i<num;i++) {
                result += va_arg( arg, int );
            }

            return  result;
        }
        int minus(int num, ...) {
            va_list arg;
            va_start(arg, num);

            int result = va_arg( arg, int );
            for(int i=1;i<num;i++) {
                result -= va_arg( arg, int );
            }

            return  result;
        }
};

#endif // RECHNER_H
