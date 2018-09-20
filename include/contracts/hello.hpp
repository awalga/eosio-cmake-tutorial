//
// Created by abel walga on 02/08/2018.
//

#ifndef EOSIO_HELLO_WORLD_HELLO_HPP
#define EOSIO_HELLO_WORLD_HELLO_HPP

#include <contracts/hello.hpp>
#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

using namespace eosio;

class hello : public eosio::contract {
 public:
  hello(account_name n);
  /// @abi action
  void hi( account_name user );
};
#endif //EOSIO_HELLO_WORLD_HELLO_HPP

