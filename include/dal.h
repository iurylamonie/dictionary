#ifndef _DAL_H_
#define _DAL_H_

#include <functional> //< std::equal_to
#include <iostream> //< std::ostream
#include <algorithm> //< std::swap
template < typename Key, //< Tipo da chave. 
		   typename Data, //< Tipo da informação.
		   typename KeyComparator = std::equal_to< Key > > //< Function de comparação de chaves.
class DAL
{
protected:
	
	/**
	 * @brief      Estrutura do nó, representando o par chave-informação.
	 */
	struct NodeAL
	{
		Key id; //< A chave.
		Data info; //< A informação.
	};

	static const int SIZE = 50; //< Tamanho default da lista.
	int m_lenght; //< Comprimento atual da lista.
	int m_capacity; //< Capacidade máxima de armazenamento.
	NodeAL * mpt_data;

public:
	
	int capacity() const { return this->m_capacity; }
	bool empty() { return ( this->m_lenght == 0 ); }
	/**
	 * @brief      Contrói o dicionario com o tamanho máximo.
	 *
	 * @param[in]  _MaxSz  O tamanho máximo.
	 */
	DAL( int _MaxSz = SIZE )
	{
		this->mpt_data = new NodeAL[_MaxSz];
		this->m_lenght = 0;
		this->m_capacity = _MaxSz;
	}
	//virtual ~DAL();

	/**
	 * @brief      Insere o par associado, chave e informação, no dicionário D.
	 * @param[in]  _newKey   A chave.
	 * @param[in]  _newInfo  A informação.
	 *
	 * @return     True se foi inserido, false caso contrário.
	 */
	bool insert( const Key & _newKey, const Data & _newInfo )
	{
		// Verifica se a lista atingiu sua capacidade máxima.
		if( this->m_lenght < this->m_capacity )
		{
			KeyComparator compFunc;
			//Percorre a lista.
			for( int i = 0; i < this->m_lenght; ++i)
			{
				//Verifica se a chave já existe na lista.
				if( this->mpt_data[i].id == _newKey ) return false;
			}
			this->mpt_data[this->m_lenght].id = _newKey;
			this->mpt_data[this->m_lenght].info = _newInfo;
			++this->m_lenght;
			return true;
		}

		return false;
	}

	/**
	 * @brief      Remove e retorna do dicionário a informação associada à chave.
	 *
	 * @param[in]  _x    A chave.
	 * @param      _s    A informação.
	 *
	 * @return     True se removeu, false caso contrário.
	 */
	bool remove( const Key & _x, Data & _s )
	{
		if(!this->empty())
		{
			for( int i = 0; i < this->m_lenght; ++i)
			{
				//Verifica se a chave existe na lista.
				if( this->mpt_data[i].id == _x )
				{
					_s = this->mpt_data[i].info;
					// Joga o par que vai ser "removido" para o fim da lista.
					std::swap(this->mpt_data[i], this->mpt_data[this->m_lenght - 1]);
					--this->m_lenght;
					return true;
				}
			}
		}

		return false;
	}

	/**
	 * @brief      Busca e recupera do dicionário a informação associada à chave.
	 *
	 * @param[in]  _x    A chave.
	 * @param      _s    A informação.
	 *
	 * @return     True se encontrou a chave, false caso contrário.
	 */
	bool search( const Key & _x, Data & _s )
	{
		if(!this->empty())
		{
			for( int i = 0; i < this->m_lenght; ++i)
			{
				//Verifica se a chave existe na lista.
				if( this->mpt_data[i].id == _x )
				{
					_s = this->mpt_data[i].info;
					return true;
				}
			}
		}
		return false;
	}

	/**
	 * @brief      Recuperam do dicionário a menor chave.
	 *
	 * @return     A menor chave.
	 */
	Key min() const
	{
		KeyComparator compFunc;
		Key menor = this->mpt_data[0].id;
		for( int i = 1; i < this->m_lenght; ++i)
		{
			// l < r
			if( compFunc( /*l*/this->mpt_data[i].id , /*r*/menor ) ) menor = this->mpt_data[i].id;
		}

		return menor;
	}
	
	/**
	 * @brief      Recuperam do dicionário a maior chave.
	 *
	 * @return     A maior chave.
	 */
	Key max() const
	{
		KeyComparator compFunc;
		Key maior = this->mpt_data[0].id;
		for( int i = 1; i < this->m_lenght; ++i)
		{
			// l < r
			if( !compFunc( /*l*/this->mpt_data[i].id , /*r*/maior ) ) maior = this->mpt_data[i].id;
		}

		return maior;
	}
	
	/**
	 * @brief      Recupera do dicionário a chave que seja imediatamente posterior a outra chave.
	 *
	 * @param[in]  _x    Outra chave.
	 * @param      _y    Chave posterior.
	 *
	 * @return     True se a chave posterior existe, false caso contrário.
	 */
	bool sucessor( const Key & _x, Key & _y )
	{
		if( !this->empty() )
		{
			for( int i = 0; i < this->m_lenght; ++i)
			{
				//Verifica se a chave existe na lista
				//E se a chave procurada não é o ultimo elemento.
				if( (this->mpt_data[i].id == _x) && ( (i + 1) != this->m_lenght ) )
				{
					_y = this->mpt_data[i+1].id;
					return true;
				}
			}
		}
		return false;
	}

	/**
	 * @brief      Recupera do dicionário a chave que seja imediatamente anterior a outra chave.
	 *
	 * @param[in]  _x    Outra chave.
	 * @param      _y    Chave anterior.
	 *
	 * @return     True se a chave anterior existe, false caso contrário.
	 */
	bool predecessor( const Key & _x, Key & _y )
	{
		if( !this->empty() )
		{
			for( int i = 0; i < this->m_lenght; ++i)
			{
				//Verifica se a chave existe na lista
				//E se a chave procurada não é o primeiro elemento.
				if( (this->mpt_data[i].id == _x) && ( (i - 1) >= 0 ) )
				{
					_y = this->mpt_data[i-1].id;
					return true;
				}
			}
		}
		return false;
	}
	inline friend std::ostream& operator<<( std::ostream& os, const DAL& _oList )
	{
		os << "[ ";
		for( int i(0); i < _oList.m_lenght; ++i)
		{
			os << "{id: " << _oList.mpt_data[i].id << ", info: "
			   << _oList.mpt_data[i].info << "} ";
		}
		os << "]";
		return os;
	}
	
};

template < typename Key, //< Tipo da chave. 
		   typename Data, //< Tipo da informação.
		   typename KeyComparator = std::equal_to< Key > > //< Function de comparação de chaves.
class DSAL : public DAL< Key, Data, KeyComparator >
{
public:
	DSAL( int _MaxSz) : DAL< Key, Data, KeyComparator >( _MaxSz ) { /*Empty*/}
	~DSAL();
	
};
#endif