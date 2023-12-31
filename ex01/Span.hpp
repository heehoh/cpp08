/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:54:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/25 01:34:33 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <set>
#include <vector>

class Span {
 private:
  std::vector<int> v_;
  unsigned int size_;
  class OutOfRange : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Span의 저장공간이 가득 찼습니다.";
    }
  };
  class TooFewElements : public std::exception {
   public:
    virtual const char *what() const throw() {
      return "Span에 저장된 수가 2개 미만입니다.";
    }
  };

 public:
  Span();
  Span(const Span &other);
  Span(unsigned int N);
  Span &operator=(const Span &other);
  ~Span();
  void addNumber(int num);
  unsigned int shortestSpan();
  unsigned int longestSpan();
  template <typename T>
  void easyAddNumber(typename T::iterator begin, typename T::iterator end) {
    for (typename T::iterator it = begin; it != end; ++it) {
      if (v_.size() == size_) throw OutOfRange();
      v_.push_back(*it);
    }
  }
};

#endif