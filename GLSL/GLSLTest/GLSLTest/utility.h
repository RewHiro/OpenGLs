#pragma once


namespace utility
{

/// <summary>
/// コピー禁止クラス
/// </summary>
class Noncopyable
{
public:

	Noncopyable() = default;

	Noncopyable(const Noncopyable&) = delete;
	Noncopyable operator= (const Noncopyable&) = delete;
};

}

namespace util = utility;