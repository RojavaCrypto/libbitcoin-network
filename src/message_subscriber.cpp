/**
 * Copyright (c) 2011-2015 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * libbitcoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/network/message_subscriber.hpp>

#include <istream>
#include <memory>
#include <string>
#include <bitcoin/bitcoin.hpp>

#define INITIALIZE_SUBSCRIBER(pool, value) \
    value##_subscriber_(std::make_shared<value##_subscriber_type>( \
        pool, #value "_sub"))

#define RELAY_CODE(code, value) \
    value##_subscriber_->relay(code, nullptr)

#define CASE_HANDLE_MESSAGE(stream, value) \
    case message_type::value: \
        return handle<message::value>(stream, value##_subscriber_)

#define CASE_RELAY_MESSAGE(stream, value) \
    case message_type::value: \
        return relay<message::value>(stream, value##_subscriber_)

#define START_SUBSCRIBER(value) \
    value##_subscriber_->start()

#define STOP_SUBSCRIBER(value) \
    value##_subscriber_->stop()

namespace libbitcoin {
namespace network {

using namespace message;

message_subscriber::message_subscriber(threadpool& pool)
  : INITIALIZE_SUBSCRIBER(pool, address),
    INITIALIZE_SUBSCRIBER(pool, alert),
    INITIALIZE_SUBSCRIBER(pool, block),
    INITIALIZE_SUBSCRIBER(pool, filter_add),
    INITIALIZE_SUBSCRIBER(pool, filter_clear),
    INITIALIZE_SUBSCRIBER(pool, filter_load),
    INITIALIZE_SUBSCRIBER(pool, get_address),
    INITIALIZE_SUBSCRIBER(pool, get_blocks),
    INITIALIZE_SUBSCRIBER(pool, get_data),
    INITIALIZE_SUBSCRIBER(pool, get_headers),
    INITIALIZE_SUBSCRIBER(pool, headers),
    INITIALIZE_SUBSCRIBER(pool, inventory),
    INITIALIZE_SUBSCRIBER(pool, memory_pool),
    INITIALIZE_SUBSCRIBER(pool, merkle_block),
    INITIALIZE_SUBSCRIBER(pool, not_found),
    INITIALIZE_SUBSCRIBER(pool, ping),
    INITIALIZE_SUBSCRIBER(pool, pong),
    INITIALIZE_SUBSCRIBER(pool, reject),
    INITIALIZE_SUBSCRIBER(pool, transaction),
    INITIALIZE_SUBSCRIBER(pool, verack),
    INITIALIZE_SUBSCRIBER(pool, version)
{
}

void message_subscriber::broadcast(const code& ec)
{
    RELAY_CODE(ec, address);
    RELAY_CODE(ec, alert);
    RELAY_CODE(ec, block);
    RELAY_CODE(ec, filter_add);
    RELAY_CODE(ec, filter_clear);
    RELAY_CODE(ec, filter_load);
    RELAY_CODE(ec, get_address);
    RELAY_CODE(ec, get_blocks);
    RELAY_CODE(ec, get_data);
    RELAY_CODE(ec, get_headers);
    RELAY_CODE(ec, headers);
    RELAY_CODE(ec, inventory);
    RELAY_CODE(ec, memory_pool);
    RELAY_CODE(ec, merkle_block);
    RELAY_CODE(ec, not_found);
    RELAY_CODE(ec, ping);
    RELAY_CODE(ec, pong);
    RELAY_CODE(ec, reject);
    RELAY_CODE(ec, transaction);
    RELAY_CODE(ec, verack);
    RELAY_CODE(ec, version);
}

code message_subscriber::load(message_type type, std::istream& stream) const
{
    switch (type)
    {
        CASE_RELAY_MESSAGE(stream, address);
        CASE_RELAY_MESSAGE(stream, alert);
        CASE_HANDLE_MESSAGE(stream, block);
        CASE_RELAY_MESSAGE(stream, filter_add);
        CASE_RELAY_MESSAGE(stream, filter_clear);
        CASE_RELAY_MESSAGE(stream, filter_load);
        CASE_RELAY_MESSAGE(stream, get_address);
        CASE_RELAY_MESSAGE(stream, get_blocks);
        CASE_RELAY_MESSAGE(stream, get_data);
        CASE_RELAY_MESSAGE(stream, get_headers);
        CASE_RELAY_MESSAGE(stream, headers);
        CASE_RELAY_MESSAGE(stream, inventory);
        CASE_RELAY_MESSAGE(stream, memory_pool);
        CASE_RELAY_MESSAGE(stream, merkle_block);
        CASE_RELAY_MESSAGE(stream, not_found);
        CASE_RELAY_MESSAGE(stream, ping);
        CASE_RELAY_MESSAGE(stream, pong);
        CASE_RELAY_MESSAGE(stream, reject);
        CASE_RELAY_MESSAGE(stream, transaction);
        CASE_RELAY_MESSAGE(stream, verack);
        CASE_RELAY_MESSAGE(stream, version);
        case message_type::unknown:
        default:
            return error::not_found;
    }
}

void message_subscriber::start()
{
    START_SUBSCRIBER(address);
    START_SUBSCRIBER(alert);
    START_SUBSCRIBER(block);
    START_SUBSCRIBER(filter_add);
    START_SUBSCRIBER(filter_clear);
    START_SUBSCRIBER(filter_load);
    START_SUBSCRIBER(get_address);
    START_SUBSCRIBER(get_blocks);
    START_SUBSCRIBER(get_data);
    START_SUBSCRIBER(get_headers);
    START_SUBSCRIBER(headers);
    START_SUBSCRIBER(inventory);
    START_SUBSCRIBER(memory_pool);
    START_SUBSCRIBER(merkle_block);
    START_SUBSCRIBER(not_found);
    START_SUBSCRIBER(ping);
    START_SUBSCRIBER(pong);
    START_SUBSCRIBER(reject);
    START_SUBSCRIBER(transaction);
    START_SUBSCRIBER(verack);
    START_SUBSCRIBER(version);
}

void message_subscriber::stop()
{
    STOP_SUBSCRIBER(address);
    STOP_SUBSCRIBER(alert);
    STOP_SUBSCRIBER(block);
    STOP_SUBSCRIBER(filter_add);
    STOP_SUBSCRIBER(filter_clear);
    STOP_SUBSCRIBER(filter_load);
    STOP_SUBSCRIBER(get_address);
    STOP_SUBSCRIBER(get_blocks);
    STOP_SUBSCRIBER(get_data);
    STOP_SUBSCRIBER(get_headers);
    STOP_SUBSCRIBER(headers);
    STOP_SUBSCRIBER(inventory);
    STOP_SUBSCRIBER(memory_pool);
    STOP_SUBSCRIBER(merkle_block);
    STOP_SUBSCRIBER(not_found);
    STOP_SUBSCRIBER(ping);
    STOP_SUBSCRIBER(pong);
    STOP_SUBSCRIBER(reject);
    STOP_SUBSCRIBER(transaction);
    STOP_SUBSCRIBER(verack);
    STOP_SUBSCRIBER(version);
}

} // namespace network
} // namespace libbitcoin
