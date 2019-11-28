#pragma once
#include <map>;

// xtransmit
#include "buffer.hpp"

// OpenSRT
#include "uriparser.hpp"

namespace xtransmit
{
namespace socket
{

	class exception : public std::exception
	{

	public:

		exception(const std::string&& err)
			: m_error_msg(err)
		{

		}

	public:

		virtual const char* what() const throw()
		{
			return m_error_msg.c_str();
		}

	private:

		const std::string m_error_msg;
	};



	class isocket
	{
	
	public:

		/** Read data from socket.
		 *
		 * @returns The number of bytes received.
		 *
		 * @throws socket::exception Thrown on failure.
		 */
		virtual size_t read(const mutable_buffer& buffer, int timeout_ms = -1) = 0;

		/** Write data to socket.
		 *
		 * @returns The number of bytes received.
		 *
		 * @throws socket::exception Thrown on failure.
		 */
		virtual int   write(const const_buffer&   buffer, int timeout_ms = -1) = 0;
		
	public:

		/** Retrieve statistics on a socket.
		 *
		 * @returns The number of bytes received.
		 *
		 * @throws socket::exception Thrown on failure.
		 */
		virtual const std::string statistics_csv(bool print_header)
		{
			return std::string();
		}

	};

}
}