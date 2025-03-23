#pragma once
#include <iostream>
#include <cmath>

template <class T>
class TComplex
{
protected:
  T re;
  T im;
public:
  T GetRe();
  void SetRe(T re_);
  T GetIm();
  void SetIm(T im_);

  TComplex();
  TComplex(T re_, T im_);
  TComplex(const TComplex<T> & p);
  ~TComplex();

  TComplex operator+ (const TComplex <T>& p);
  TComplex operator* (const TComplex <T>& p);
  TComplex operator/ (const TComplex <T>& p);
  TComplex operator- (const TComplex <T>& p);

  TComplex& operator+= (const TComplex <T>& p);
  TComplex& operator*= (const TComplex <T>& p);
  TComplex& operator/= (const TComplex <T>& p);
  TComplex& operator-= (const TComplex <T>& p);

  TComplex& operator= (const TComplex <T>& p);

  bool operator== (const TComplex <T>& p);
  bool operator!= (const TComplex <T>& p);

  T Abs();

  template <class V>
  friend std::ostream& operator <<(std::ostream& o, TComplex<V>& p);

  template <class V>
  friend std::istream& operator>>(std::istream& i, TComplex<V>& p);
};

template <class T>
inline T TComplex<T>::GetRe()
{
  return re;
}

template <class T>
inline void TComplex<T>::SetRe(T re_)
{
  re = re_;
}

template <class T>
inline T TComplex<T>::GetIm()
{
  return im;
}

template <class T>
inline void TComplex<T>::SetIm(T im_)
{
  im = im_;
}

template <class T>
TComplex<T>::TComplex()
{
  re = 0;
  im = 0;
}

template <class T>
TComplex<T>::TComplex(T re_, T im_)
{
  re = re_;
  im = im_;
}

template <class T>
TComplex<T>::TComplex(const TComplex<T> & p)
{
  re = p.re;
  im = p.im;
}

template <class T>
TComplex<T>::~TComplex()
{

}

template <class T>
TComplex<T> TComplex<T>::operator+ (const TComplex <T>& p)
{
  return TComplex(re + p.re, im + p.im);
}

template <class T>
TComplex<T> TComplex<T>::operator- (const TComplex <T>& p)
{
  return TComplex(re - p.re, im - p.im);
}

template <class T>
TComplex<T> TComplex<T>::operator* (const TComplex <T>& p)
{
  return TComplex(re * p.re - im * p.im, re * p.im + im * p.re);
}

template <class T>
TComplex<T> TComplex<T>::operator/ (const TComplex <T>& p)
{
  if (p.re == 0 && p.im == 0)
    throw std::invalid_argument("Can't divide by zero");
  return TComplex((re * p.re + im * p.im) / (p.im * p.im + p.re * p.re),
                  (re * p.im - im * p.re) / (p.im * p.im + p.re * p.re));
}

template <class T>
TComplex<T>& TComplex<T>::operator+= (const TComplex <T>& p)
{
  T re_ = re + p.re;
  T im_ =  im + p.im;
  re = re_;
  im = im_;
  return *this;
}

template <class T>
TComplex<T>& TComplex<T>::operator-= (const TComplex <T>& p)
{
  T re_ = re - p.re;
  T im_ =  im - p.im;
  re = re_;
  im = im_;
  return *this;
}

template <class T>
TComplex<T>& TComplex<T>::operator*= (const TComplex <T>& p)
{
  T re_ = re * p.re - im * p.im;
  T im_ =  re * p.im + im * p.re;
  re = re_;
  im = im_;
  return *this;
}

template <class T>
TComplex<T>& TComplex<T>::operator/= (const TComplex <T>& p)
{
  if (p.re == 0 && p.im == 0)
    throw std::invalid_argument("Can't divide by zero");
  T re_ = (re * p.re + im * p.im) / (p.im * p.im + p.re * p.re);
  T im_ =  (re * p.im - im * p.re) / (p.im * p.im + p.re * p.re);
  re = re_;
  im = im_;
  return *this;
}

template <class T>
TComplex<T>& TComplex<T>::operator= (const TComplex <T>& p)
{
  re = p.re;
  im = p.im;
  return *this;
}

template <class T>
bool TComplex<T>::operator== (const TComplex <T>& p)
{
  return (re == p.re) && (im == p.im);
}

template <class T>
bool TComplex<T>::operator!= (const TComplex <T>& p)
{
  return (re != p.re) || (im != p.im);
}

template <class T>
T TComplex<T>::Abs()
{
 return std::sqrt(re * re + im * im);
}

template<class V>
inline std::ostream& operator<<(std::ostream& o, TComplex<V>& p)
{
  if (p.re == 0 && p.im == 0)
  {
   o << 0;
  } else {
    if (p.re != 0)
    {
      o << p.re << ' ';
      if (p.im > 0)
        o << " + " << p.im << " * i";
      if (p.im < 0)
        o << " - " << p.im << " * i";
    } else {
      o << p.im << " * i";
    }
  }

}

template <class V>
std::istream& operator>>(std::istream& i, TComplex<V>& p)
{
  V re_;
  V im_;
  i >> re_ >> im_;
  p.setRe(re_);
  p.setIm(im_);
}