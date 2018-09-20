//
// Created by abel walga on 02/08/2018.
//
#include "contracts/hello.hpp"

using namespace eosio;

hello::hello(account_name n) : contract(n) {}

void hello::hi(account_name user) {
  print("Hello, EOS", name{user});
}

EOSIO_ABI(hello, (hi))
