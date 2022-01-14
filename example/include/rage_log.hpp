#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <codecvt>
#include <vector>
#include <memory>

namespace rage
{
	class Log : protected std::ostream
	{
	public:
		enum Color
		{
			RESET,
			BLACK, LBLACK,
			RED, LRED,
			GREEN, LGREEN,
			BLUE, LBLUE,
			YELLOW, LYELLOW,
			MAGENTA, LMAGENTA,
			CYAN, LCYAN,
			WHITE, LWHITE
		};

		using StdStreamManip = std::ostream& (*)(std::ostream&);
		using LogManip = Log & (*)(Log&);

		Log& Write(const std::string& val)
		{
			for (auto& s : streams)
				s->Put(val);

			return *this;
		}

		template<class T>
		Log& Put(const T& val)
		{
			std::cout << val;
			return *this;
		}

		Log& Put(bool val)
		{
			return Put(val ? "true" : "false");
		}

		Log& Put(LogManip val)
		{
			return val(*this);
		}

		Log& Put(StdStreamManip val)
		{
			std::cout << val;
			return *this;
		}

		template<class... Args>
		Log& Put(LogManip val, const Args&... args)
		{
			return Put(val).Put(args...);
		}

		template<class T, class... Args>
		Log& Put(const T& val, const Args&... args)
		{
			return Put(val).Put(" ").Put(args...);
		}

		Log& PutTime()
		{
			const time_t t = time(nullptr);
			tm tt;

			localtime_s(&tt, &t);

			std::cout << std::put_time(&tt, "[%H:%M:%S]") << std::flush;
			return *this;
		}

		Log& PutColor(Color col)
		{
			*this << std::flush;

			for (auto& s : streams)
				s->PutColor(col);

			return *this;
		}

		template<class T> Log& operator<<(const T& val) { return Put(val); }
		Log& operator<<(StdStreamManip val) { return Put(val); }
		Log& operator<<(LogManip val) { return Put(val); }

		// Manipulators
		static Log& Reset(Log& log) { return log.PutColor(RESET); }
		static Log& Black(Log& log) { return log.PutColor(BLACK); }
		static Log& LBlack(Log& log) { return log.PutColor(LBLACK); }
		static Log& Red(Log& log) { return log.PutColor(RED); }
		static Log& LRed(Log& log) { return log.PutColor(LRED); }
		static Log& Green(Log& log) { return log.PutColor(GREEN); }
		static Log& LGreen(Log& log) { return log.PutColor(LGREEN); }
		static Log& Blue(Log& log) { return log.PutColor(BLUE); }
		static Log& LBlue(Log& log) { return log.PutColor(LBLUE); }
		static Log& Yellow(Log& log) { return log.PutColor(YELLOW); }
		static Log& LYellow(Log& log) { return log.PutColor(LYELLOW); }
		static Log& Magenta(Log& log) { return log.PutColor(MAGENTA); }
		static Log& LMagenta(Log& log) { return log.PutColor(LMAGENTA); }
		static Log& Cyan(Log& log) { return log.PutColor(CYAN); }
		static Log& LCyan(Log& log) { return log.PutColor(LCYAN); }
		static Log& White(Log& log) { return log.PutColor(WHITE); }
		static Log& LWhite(Log& log) { return log.PutColor(LWHITE); }
		static Log& Endl(Log& log) { return log.Put(std::endl).Put(std::dec).PutColor(WHITE); }
		static Log& Time(Log& log) { return log.PutTime(); }

		struct Log_Base
		{
			virtual Log& Begin() const = 0;
			template<class... Args> Log& operator()(const Args&... args) const { return Begin().Put<Args...>(args...).Put(Endl); }
			template<class T> Log& operator<<(const T& val) const { return Begin().Put<T>(val); }
		};

		static constexpr struct Log_Raw : public Log_Base {
			Log& Begin() const override { return Instance(); }
		} Raw{};

		static constexpr struct Log_Done : public Log_Base {
			Log& Begin() const override { return Instance().Put(Green, " - [DONE]", Reset); }
		} Done{};

		static constexpr struct Log_Debug : public Log_Base {
			Log& Begin() const override { return Instance().Put(Cyan, " - [DEBUG]", Reset); }
		} Debug{};

		static constexpr struct Log_Error : public Log_Base {
			Log& Begin() const override { return Instance().Put(Red, " - [ERROR]", Reset); }
		} Error{};

		static constexpr struct Log_Info : public Log_Base {
		private:
			Log& Begin() const override { return Instance().Put(Yellow, " - [INFO]", Reset); }
		} Info{};

		static Log& Instance() noexcept
		{
			static Log s;
			return s;
		}

		class Stream
		{
		public:
			virtual Stream& Put(const std::string& val) = 0;
			virtual Stream& PutColor(Color color) = 0;
		};

		void AddOut(Stream* stream) { streams.emplace_back(stream); }

		static void Push(Stream* stream) { Instance().AddOut(stream); }

		class ConsoleStream : public Stream
		{
		public:
			Stream& Put(const std::string& val) override
			{
				std::cout << val;

				return *this;
			}

			Stream& PutColor(Color val) override
			{
				switch (val)
				{
				case RESET:
					std::cout << "\033[0m";
					break;
				case BLACK:
					std::cout << "\033[30m";
					break;
				case LBLACK:
					std::cout << "\033[90m";
					break;
				case RED:
					std::cout << "\033[31m";
					break;
				case LRED:
					std::cout << "\033[91m";
					break;
				case GREEN:
					std::cout << "\033[32m";
					break;
				case LGREEN:
					std::cout << "\033[92m";
					break;
				case BLUE:
					std::cout << "\033[34m";
					break;
				case LBLUE:
					std::cout << "\033[94m";
					break;
				case YELLOW:
					std::cout << "\033[33m";
					break;
				case LYELLOW:
					std::cout << "\033[93m";
					break;
				case MAGENTA:
					std::cout << "\033[35m";
					break;
				case LMAGENTA:
					std::cout << "\033[95m";
					break;
				case CYAN:
					std::cout << "\033[36m";
					break;
				case LCYAN:
					std::cout << "\033[96m";
					break;
				case WHITE:
					std::cout << "\033[37m";
					break;
				case LWHITE:
					std::cout << "\033[97m";
					break;
				}

				return *this;
			}

		};

	private:
		class Buffer : public std::streambuf
		{
			static const std::size_t BUF_SIZE = 1024;

			char buf[BUF_SIZE];

		public:
			using Traits = std::char_traits<char>;

			Buffer() { setp(buf, buf + BUF_SIZE); }

		protected:
			virtual Traits::int_type overflow(Traits::int_type c = Traits::eof()) override
			{
				put(pbase(), pptr());
				if (c != Traits::eof()) {
					char c2 = c;
					put(&c2, &c2 + 1);
				}
				setp(buf, buf + BUF_SIZE);

				return c;
			}

			virtual int sync() override
			{
				put(pbase(), pptr());
				setp(buf, buf + BUF_SIZE);
				return 0;
			}

		private:
			void put(const char* begin, const char* end) { Log::Instance().Write(std::string(begin, end)); }
		};

		Log() :std::ostream(&buf) { };
		Log(const Log&) = delete;
		Log& operator=(const Log&) = delete;

		Buffer buf;
		std::vector<std::unique_ptr<Stream>> streams;
	};
}
