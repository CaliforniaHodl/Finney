# Bitcoin Finney

A minimal Bitcoin node for L3 anchoring. Named after [Hal Finney](https://en.wikipedia.org/wiki/Hal_Finney_(computer_scientist)).

Finney is a stripped-down fork of [Bitcoin Knots](https://bitcoinknots.org/) that retains only what's needed to run a Bitcoin daemon with wallet support for OP_RETURN transaction anchoring. GUI, test suites, ZMQ, Tor/I2P, UPnP, BDB wallets, and utility binaries have been removed.

**Output:** `bitcoind` + `bitcoin-cli` (SQLite wallet only).

## Dependencies

| Dependency | Purpose |
|------------|---------|
| CMake 3.22+ | Build system |
| C++20 compiler | GCC 11+, Clang 16+, or MSVC 2022+ |
| Boost (headers) | Data structures |
| libevent 2.1.8+ | Async networking |
| SQLite 3.7.17+ | Wallet storage |

## Build

```bash
cd Finney
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
```

Binaries are placed in `build/bin/`.

## Configuration for L3

Start the daemon on testnet:

```bash
./build/bin/bitcoind -testnet -server -daemon -txindex
```

Create a wallet for anchoring:

```bash
./build/bin/bitcoin-cli -testnet createwallet "l3"
```

Configure `bitcoin.conf` for L3 use:

```ini
server=1
txindex=1
rpcuser=l3node
rpcpassword=<secure-password>
```

## What's Included

- Core Bitcoin node (networking, validation, consensus, script engine, crypto)
- Wallet with SQLite backend (fund and sign OP_RETURN anchors)
- RPC server (CLI interaction with daemon)
- secp256k1, LevelDB, univalue, minisketch (embedded libraries)
- Block indexes (txindex for anchor lookup)

## What's Removed

GUI (Qt), ZMQ, Tor/I2P, UPnP/NAT-PMP, BDB wallets, external signer, IPC/multiprocess, test suites, benchmarks, utility binaries (bitcoin-tx, bitcoin-util, bitcoin-wallet), CI infrastructure, build dependency recipes.

## License

Bitcoin Finney is released under the terms of the MIT license. See [COPYING](COPYING) for more information.

## Related

- [bitcoin-l3](../bitcoin-l3/) -- The L3 anchoring layer that uses this node (18 CLI commands, VeilCloud privacy primitives, P2P network)
- [Bitcoin Knots](https://bitcoinknots.org/) -- Upstream project
