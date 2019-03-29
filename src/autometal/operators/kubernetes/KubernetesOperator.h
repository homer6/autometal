#pragma once


namespace autometal{
namespace operators{

	class KubernetesOperator{

		public:

			KubernetesOperator();

			void run();

			void installPreflight();
			void install();
			void remove();


	};


}
}