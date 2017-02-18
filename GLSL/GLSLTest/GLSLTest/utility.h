#pragma once


namespace utility
{

/// <summary>
/// コピー禁止クラス
/// </summary>
class Noncopyable
{
public:
	Noncopyable(Noncopyable&) = delete;
	Noncopyable operator= (Noncopyable&) = delete;
};

}