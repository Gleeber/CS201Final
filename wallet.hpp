//
//  wallet.hpp
//  CS201FinalLocal
//
//  Created by Andrew Adler on 11/29/17.
//  Copyright © 2017 Andrew Adler. All rights reserved.
//

#ifndef FILE_WALLET_HPP_INCLUDED
#define FILE_WALLET_HPP_INCLUDED

class Wallet {
public:
    static bool setBet();
    static void win();
	static void tie();
    static void showWallet();
	static int getWallet();
private:
    static int _currentMoney;
    static int _wager;
};

#endif // #ifndef FILE_WALLET_HPP_INCLUDED
