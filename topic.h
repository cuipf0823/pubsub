#ifndef PUB_TOPIC_H
#define PUB_TOPIC_H
#include <set>
#include <muduo/net/TcpConnection.h>

namespace pub
{

//��û���˺ŵĸ��ֻ�������ߵ�¼����
typedef std::set<muduo::net::TcpConnectionPtr> Subscribers;

class Topic
{
public:
	Topic(const std::string& topic):
		topic_(topic)
	{

	}
	~Topic()
	{

	}
	//��������
	bool Subscribe(const muduo::net::TcpConnectionPtr& con);
	//ȡ������
	void UnSubscribe(const muduo::net::TcpConnectionPtr& con);
	//����
	void Publish(const std::string& content, muduo::Timestamp time);
	//��ȡȫ��������
	const Subscribers& subscribers() const
	{
		return subscribers_;
	}
	const std::string& topic() const
	{
		return topic_;
	}
	const std::string& content() const
	{
		return content_;
	}
private:
	std::string topic_;
	std::string content_;
	Subscribers subscribers_;
	muduo::Timestamp last_pub_time_;   //����ʱ��
};

}
#endif