void dfs()//递归函数，直至识别完全部串
{
	if(stack.at(stack.size()-1)==syn)//如果相同能识别就弹出
	{
		stack.pop_back();
		return;
	}
	switch(stack.at(stack.size()-1))//否则就继续用文法转换
	{//识别不同的文法
	case A:
		{
			if(syn==1)
			{
				stack.pop_back();
				stack.push_back(A);
				stack.push_back(3);
				stack.push_back(B);
				stack.push_back(1);
			}
			else if(syn==4)
			{
				stack.pop_back();
				stack.push_back(A);
				stack.push_back(B);
				stack.push_back(4);
			}
			else if(syn==18)
			{
				stack.pop_back();
				stack.push_back(A);
				stack.push_back(E);
			}
			else if(syn==22)
			{
				stack.pop_back();
			}
			else
			{
				switch(syn)
				{
				case 17:cout<<"error at"<<"<"<<syn<<","<<sum<<">"<<endl;break;
				default:cout<<"error at"<<"<"<<syn<<","<<token<<">"<<endl;break;
				}
				return;
			}
		}
		break;
	case B:
		{
			if(syn==20||syn==17||syn==18)
			{
				stack.pop_back();
				stack.push_back(C);
				stack.push_back(D);
				stack.push_back(C);
			}
			else
			{
				switch(syn)
				{
				case 17:cout<<"error at"<<"<"<<syn<<","<<sum<<">"<<endl;break;
				default:cout<<"error at"<<"<"<<syn<<","<<token<<">"<<endl;break;
				}
				return;
			}
		}
		break;
	case C:
		{
			if(syn==20||syn==17||syn==18)
			{
				stack.pop_back();
				stack.push_back(C2);
				stack.push_back(X);
			}
			else
			{
				switch(syn)
				{
				case 17:cout<<"error at"<<"<"<<syn<<","<<sum<<">"<<endl;break;
				default:cout<<"error at"<<"<"<<syn<<","<<token<<">"<<endl;break;
				}
				return;
			}
		}
		break;
	case D:
		{
			for(int i=10;i<=15;i++)
			{
				if(syn==i)
				{
					stack.pop_back();
					stack.push_back(syn);
				}
			}
			if(syn<10||syn>15)
			{
				switch(syn)
				{
				case 17:cout<<"error at"<<"<"<<syn<<","<<sum<<">"<<endl;break;
				default:cout<<"error at"<<"<"<<syn<<","<<token<<">"<<endl;break;
				}
				return;
			}
		}
		break;
	case E:
		{
			if(syn==18)
			{
				stack.pop_back();
				stack.push_back(16);
				stack.push_back(C);
				stack.push_back(9);
				stack.push_back(18);
			}
			else
			{
				switch(syn)
				{
				case 17:cout<<"error at"<<"<"<<syn<<","<<sum<<">"<<endl;break;
				default:cout<<"error at"<<"<"<<syn<<","<<token<<">"<<endl;break;
				}
				return;
			}
		}
		break;
	case C2:
		{
			if(syn==5)
			{
				stack.pop_back();
				stack.push_back(C2);
				stack.push_back(X);
				stack.push_back(5);
			}
			else if(syn==6)
			{
				stack.pop_back();
				stack.push_back(C2);
				stack.push_back(X);
				stack.push_back(6);
			}
			else if(syn==19)
			{
				stack.pop_back();
			}
			else if(syn==1||syn==3||syn==4||syn>=10&&syn<=15||syn==16||syn==18)
			{
				stack.pop_back();
			}
			else
			{
				switch(syn)
				{
				case 17:cout<<"error at"<<"<"<<syn<<","<<sum<<">"<<endl;break;
				default:cout<<"error at"<<"<"<<syn<<","<<token<<">"<<endl;break;
				}
				return;
			}
		}
		break;
	case X:
		{
			if(syn==17||syn==20||syn==18)
			{
				stack.pop_back();
				stack.push_back(X2);
				stack.push_back(Y);
			}
			else
			{
				switch(syn)
				{
				case 17:cout<<"error at"<<"<"<<syn<<","<<sum<<">"<<endl;break;
				default:cout<<"error at"<<"<"<<syn<<","<<token<<">"<<endl;break;
				}
				return;
			}
		}
		break;
	case X2:
		{
			if(syn==7)
			{
				stack.pop_back();
				stack.push_back(X2);
				stack.push_back(Y);
				stack.push_back(7);
			}
			else if(syn==8)
			{
				stack.pop_back();
				stack.push_back(X2);
				stack.push_back(Y);
				stack.push_back(8);
			}
			else if(syn==1||syn==3||syn==4||syn>=10&&syn<=15||syn==16||syn==18||syn==5||syn==6)
			{
				stack.pop_back();
			}
			else
			{
				switch(syn)
				{
				case 17:cout<<"error at"<<"<"<<syn<<","<<sum<<">"<<endl;break;
				default:cout<<"error at"<<"<"<<syn<<","<<token<<">"<<endl;break;
				}
				return;
			}
		}
		break;
	case Y:
		{
			if(syn==17)
			{
				stack.pop_back();
				stack.push_back(17);
			}
			else if(syn==18)
			{
				stack.pop_back();
				stack.push_back(18);
			}
			else if(syn==20)
			{
				stack.pop_back();
				stack.push_back(19);
				stack.push_back(C);
				stack.push_back(20);
			}
			else
			{
				switch(syn)
				{
					case 17:cout<<"error at"<<"<"<<syn<<","<<sum<<">"<<endl;break;
					default:cout<<"error at"<<"<"<<syn<<","<<token<<">"<<endl;break;
				}
				return;
			}
		}
		break;
	default:
		{
		switch(syn)
		{
			case 17:cout<<"error at"<<"<"<<syn<<","<<sum<<">"<<endl;break;
			default:cout<<"error at"<<"<"<<syn<<","<<token<<">"<<endl;break;
		}
			return;
		}
		break;
	}
	dfs();//递归调用
}
