import 'package:a_s_c/features/admin/services/admin_services.dart';
import 'package:a_s_c/models/product.dart';
import 'package:flutter/material.dart';
import 'package:flutter_spinkit/flutter_spinkit.dart';

class ListOfProducts extends StatefulWidget {
  const ListOfProducts({super.key});
  @override
  State<ListOfProducts> createState() => _ListOfProductsState();
}

class _ListOfProductsState extends State<ListOfProducts> {
  List<Product>? products;
  final AdminServices adminServices = AdminServices();
  @override
  void initState() {
    fetchAllProducts();
    super.initState();
  }

  fetchAllProducts() async {
    products = await adminServices.fetchAllProducts(context);
    setState(() {});
  }

  @override
  Widget build(BuildContext context) {
    return products == null
        ? const SpinKitCircle(
            color: Colors.deepPurple,
          )
        : ListView.builder(
            itemCount: products!.length,
            itemBuilder: (context, index) {
              return products!.map(
                (e) => Card(
                  child: ListTile(
                    leading: SizedBox(
                      child: Image.network(
                        e.images.toString(),
                      ),
                    ),
                    title: Column(
                      children: [
                        Text(e.name),
                        Text(e.description),
                        Text('${e.price}')
                      ],
                    ),
                    subtitle: Text(e.category),
                    trailing: Text('${e.quantity}'),
                  ),
                ),
              ) as Widget;
            });
  }
}
